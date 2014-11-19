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
#define SPACESHIP_START_X 550


int field[FIELD_WIDTH][FIELD_HEIGHT];
int movement;
int shot;
int levelcleared;
int gameover;
int change;
<<<<<<< HEAD
int block_direction;
=======
game_object *blocks;
>>>>>>> 5a450e7fb6e7a8622aecc383c988058a01dd7f5d


//initializing a new game: create field, create blocks, create spaceship.
int game_init(){
    
    //initialize the field
    int i, j;
    for (i = 0; i < FIELD_WIDTH; i++){
        for (j = 0; j< FIELD_HEIGHT ; j++){
            field[i][j] = 0;   //field: 0 = blank, 1= block(enemy), 2=spaceship, 3=rock, 4= laser
        }
    }
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
    game_object *spaceship = malloc(sizeof(game_object));
<<<<<<< HEAD
    spaceship.number = 1;
    spaceship.color= WHITE;
    spaceship.x_location = SPACESHIP_START_X;
    spaceship.y_location = (FIELD_WIDTH - 8)/2;
    spaceship.lives = 3;
    spaceship.width = 8;
    spaceship.height = 6;
    spaceship.type = 2;
    
    shot = 0;
=======
    spaceship->number = 1;
    spaceship->color= WHITE;
    spaceship->x_location = SPACESHIP_START_X;
    spaceship->y_location = (FIELD_WIDTH - 8)/2;
    spaceship->lives = 3;
    spaceship->width = 8;
    spaceship->height = 6;
    spaceship->type = 2;
 
>>>>>>> 5a450e7fb6e7a8622aecc383c988058a01dd7f5d
    return 1;
}

//check different inputs and write the EVENT;
void event()
{
    check_input();
}

//functions to use in the game loop
void calculate_laser(game_object laser)
{
<<<<<<< HEAD
	switch (laser.type)
		case 4:		//enemy laser
			laser.y_location -= LASERSPEED;
			break;
		case 5:
			laser.y_location += LASERSPEED;
			break;
		default
            return 0;
=======
	switch (laser.type){
		case 2:		//enemy laser
			laser.y_location += LASERSPEED;
			break;
		case 3:
			laser.y_location -= LASERSPEED;
			break;
		default:
			break;
	}

>>>>>>> 5a450e7fb6e7a8622aecc383c988058a01dd7f5d
}

void calculate_blocks()
{
    //for start blocks doesnt move
}

void calculate_spaceship()
{
    if (MOVEMENT){
        spaceship->x_location += MOVEMENT;
    }
}

<<<<<<< HEAD
int isHit(game_object laser, game_object block){
    int i, j;
}

int detect_hit(){
    int i,j,n;
    for (i=0; n<NOFBLOCKS; i++){
        isHit(laser, blocks[i]);
    }//for (every laser, check for collision)
=======
void detect_hit(){
    //for (every laser, check for collision)
>>>>>>> 5a450e7fb6e7a8622aecc383c988058a01dd7f5d
        //if collision, do the thing. else do nothing
}


<<<<<<< HEAD

int tick()
=======
void tick()
>>>>>>> 5a450e7fb6e7a8622aecc383c988058a01dd7f5d
{
    calculate_spaceship();
    calculate_blocks();
    //calculate_laser();
    detect_hit();

    // new_positions_of_things();
    // CHANGE = is_changed();
}


int game_end()
{
<<<<<<< HEAD
    free (spaceship);
    free (blocks);//free resources or something like that;
=======
    //free resources or something like that;

>>>>>>> 5a450e7fb6e7a8622aecc383c988058a01dd7f5d
    return 0;
}

void gametick(){
	render(field);

}



