//gametick.c

//#include <gametick.h>
#include <stdlib.h>
#include <stdio.h>
#include <objects.h>
#include <renderer.h>

#include <eventHandler.h>


#define LASERSPEED 5
#define NOFBLOCKS 30
#define LIVES 3
#define BLOCK_WIDTH 8
#define BLOCK_HEIGHT 4
#define SPACESHIP_START_Y 550


int field[FIELD_WIDTH][FIELD_HEIGHT];
int movement;
int shot;
int levelcleared;
int gameover;
int change;
game_object *spaceship;
game_object *blocks;
game_object *laser_array;


//initializing a new game: create field, create blocks, create spaceship.
int game_init(){

    //initialize the field
    int i, j;
    for (i = 0; i < FIELD_WIDTH; i++){
        for (j = 0; j< FIELD_HEIGHT ; j++){
            field[i][j] = 0;   //field: 0 = blank, 1= block(enemy), 2=spaceship, 3=rock, 4= laser
        }
    }
    //initialize lasers with no initial lasers
    typedef struct laser_array{
        game_object *first_laser;
    }laser_array;


    laser_array *lasers = malloc(sizeof(laser_array));
    lasers->first_laser = NULL;

    //initialisiere blöcke
    blocks = malloc(NOFBLOCKS*sizeof(game_object));

    game_object *block;
    for (i=0; i < NOFBLOCKS; i++){

        block->number = i;
        block->color = WHITE;
        block->x_location = 20 + (i*20) % FIELD_WIDTH;
        block->y_location = 10 + (i*20/FIELD_WIDTH*10);
        block->lives = 1;
        block->width = BLOCK_WIDTH;
        block->height = BLOCK_HEIGHT;
        block->type = 1;
        blocks[i] = *block;
        //in jeder 20x10 kasten wird ein block erstellen
    }

    /* spaceship (TODO: rocks not yet)
     * SIZE: 8x6, Position 550, centered, 3 lives
     *
     */
    spaceship = malloc(sizeof(game_object));
    spaceship->number = 1;
    spaceship->color= WHITE;
    spaceship->x_location = (FIELD_WIDTH - 8)/2;
    spaceship->y_location = SPACESHIP_START_Y;
    spaceship->lives = 3;
    spaceship->width = 8;
    spaceship->height = 6;
    spaceship->type = 2;

    shot = 0;

    return 1;
}

//check different inputs and write the EVENT;
void event()
{
    check_input();
}

//functions to use in the game loop
void calculate_laser(game_object *laser)
{
	switch (laser->type){
		case 1:		//enemy laser
			laser->y_location += LASERSPEED;
			break;
		case 2:
			laser->y_location -= LASERSPEED;
			break;
		default:
			break;
	}
    if (laser->y_location > FIELD_WIDTH || laser->y_location <= 0)
        terminateLaser (laser);
}

//blocks shoot occasionally
void calculate_blocks()
{
    //for start blocks doesnt move
    int i;
    for (i=0; i<NOFBLOCKS; i++){
        int possibleshot = rand() % 300;
        if (possibleshot <= 1){
            shootLaser(blocks[i]);
        }
    }
}


void calculate_spaceship()
{
    if (MOVEMENT < 0){
        if (spaceship->x_location + MOVEMENT > 0 ){
            spaceship->x_location += MOVEMENT;
        }else {
            spaceship->x_location = 1;
        }
    }else if (MOVEMENT > 0){
        if (spaceship->x_location + MOVEMENT < FIELD_WIDTH ){
            spaceship->x_location += MOVEMENT;
        }else{
            spaceship->x_location = FIELD_WIDTH -1;
        }
    }
//    if(SHOT){
//        if(!shot){
//            shootLaser(spaceship);
//        }
//    }
}


void terminateLaser(game_object *laser)
{
    if (laser->type == 2)
        shot = 0;
    //somehow laser = laser -> next; im not sure jet.

}

void shootLaser(game_object *shooter)
{
    //lasers intrinsic values
    game_object *laser = malloc(sizeof(game_object));
    laser->type = shooter->type;
    laser->color = WHITE;
    laser->next = NULL;
    laser->x_location = shooter->x_location + (shooter->width/2 + 1);
    if (shooter->type == 1){ //enemy laser
        laser->y_location = shooter->y_location + shooter->height;
    }
    if (shooter->type == 2){
        laser->y_location = shooter->y_location;
    }

    //add laser to the laser array
    game_object *currentLaser = laser_array;
    while (currentLaser->next){
        currentLaser = currentLaser->next;
    }
    currentLaser->next = laser;
}

int isHit(game_object *laser, game_object *block)
{
    int hit = 0;
    if ((block->lives > 0) && (block->type != laser->type && (block->x_location <= laser->x_location) && block->x_location + block->width >= laser->x_location)){
        switch (laser->type){
            case 1: //enemy laser
                if ((laser->y_location - LASERSPEED < block->y_location) && laser->y_location >= block->y_location) {
                    hit = 1;
                    block->lives =- 1;
                }
                break;
            case 2:
                if ((laser->y_location + LASERSPEED > block->y_location) && laser->y_location <= block->y_location) {
                    hit = 1;
                    block->lives =- 1;
                }
                break;

            default:
                break;
        }
    }
    return hit;
}

int detect_hit(game_object *laser)
{
    if (isHit(laser, spaceship)){
        terminateLaser(laser);
        return 1;
    }
    int i;
    for (i=0; i < NOFBLOCKS; i++){
        if (isHit(laser, &blocks[i])){
            if(blocks[i].lives <= 0) blocks[i].color = BLACK;
            terminateLaser(laser);
        }
    }
}

void tick()

{
    calculate_spaceship();
    calculate_blocks();
    game_object *actual_laser = laser_array;
    while (actual_laser){
        calculate_laser(actual_laser);
        detect_hit(actual_laser);
        actual_laser = actual_laser->next;
    }

    // new_positions_of_things();
    // CHANGE = is_changed();
}


int game_end()
{
    //all lasers
//    free (laser);
    free (laser_array);
    free (spaceship);
    free (blocks);
    return 0;
}

void gametick(){
	render(field);

}



