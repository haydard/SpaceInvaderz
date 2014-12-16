//gametick.c

//#include <gametick.h>
#include <stdlib.h>
#include <stdio.h>
#include "objects.h"
#include "eventHandler.h"
#include "SDL/SDL.h"
#include "gametick.h"


int shot_fired;
int levelcleared;
int change;
game_object *spaceship;
game_object *blocks;

typedef struct Laser_array{
    game_object *first_laser;
    int runningNoofLasers;
}laser_array;

laser_array *lasers;

//initializing a new game: create field, create blocks, create spaceship.

/*************************************************
 * Block 1: Init
 ***********************************************/
int game_init(){

    //initialize the field
    int i, j;
    for (i = 0; i < FIELD_WIDTH; i++){
        for (j = 0; j< FIELD_HEIGHT ; j++){
            field[i][j] = 0;   //field: 0 = blank, 1= block(enemy), 2=spaceship, 3=rock, 4= laser
        }
    }
    //initialize lasers with no initial lasers
    //game_object *spaceship_laser just another laser
    
    

    //first laser with type 0, placeholder to make later laser actions easier.
    lasers = malloc(sizeof(laser_array));
    lasers->first_laser = malloc(sizeof(game_object));
    lasers->first_laser->type = 0;
    lasers->first_laser->next = NULL;
    lasers->first_laser->number = 0;
    lasers->runningNoofLasers = 0;
    
    //initialisiere blöcke
    blocks = malloc(NOFBLOCKS*sizeof(game_object));

    game_object *block;
    for (i=0; i < NOFBLOCKS; i++){

        block->number = i;
        block->color = WHITE;
        block->x_location = 20 + (i*40) % (FIELD_WIDTH-40);
        block->y_location = 20 + (i*20/FIELD_WIDTH) *20;
        block->lives = 1;
        block->width = BLOCK_WIDTH;
        block->height = BLOCK_HEIGHT;
        block->type = 1;    //enemy
        blocks[i] = *block;
        //in jeder 40x20 kasten wird ein block erstellen
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
    spaceship->width = 9;
    spaceship->height = 6;
    spaceship->type = 2;  //allied

    //no laser shot_fired, spaceship idle
    shot_fired = 0;
    movement = 0;
    shooting = 0;
    
    // TODO: SDL Init
    
    return 1;
    
    
}

//check different inputs and write the EVENT;
/* TODO : SDL event shooting, shot fired
 void event()
{
    check_input();
}
*/

//functions to use in the game loop
/*************************************************
 * Block 2: Game methods, laser, spaceship
 **************************************************/
//adding a new laser to array
void shoot_laser(game_object *shooter)
{
    //lasers intrinsic values
    game_object *laser = malloc(sizeof(game_object));
    laser->type = shooter->type;
    laser->color = WHITE;
    laser->next = NULL;
    laser->number = lasers->runningNoofLasers;
    laser->x_location = shooter->x_location + (shooter->width/2 + 1);
    if (shooter->type == 1){ //enemy laser
        laser->y_location = shooter->y_location + shooter->height;
    }
    if (shooter->type == 2){
        laser->y_location = shooter->y_location;
    }
    
    //add laser to the laser array
    game_object **currentLaser = &lasers->first_laser;
    while ((*currentLaser)->next){
        currentLaser = &(*currentLaser)->next;
    }
    (*currentLaser)->next = laser;
    lasers->runningNoofLasers ++;
}

//removing a laser from the array
void terminate_laser(game_object *laser)
{
    game_object **currentLaser = &lasers->first_laser;
    while (laser->number != (*currentLaser)->next->number){
        currentLaser = &(*currentLaser)->next;
    }
    //error check
    if (!(*currentLaser)->next) printf("laser_termination_error");
    
    (*currentLaser)->next = (*currentLaser)->next->next;
    free ((*currentLaser)->next);
    
    if (laser->type == 2)
        shot_fired = 0;
    
}

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
        terminate_laser(laser);
}



//blocks shoot occasionally
void calculate_blocks()
{
    //for start blocks doesnt move
    int i;
    for (i=0; i<NOFBLOCKS; i++){
        int possibleshot = rand() % 3000;
        if (possibleshot < 1){
            shoot_laser(&blocks[i]);
        }
    }
}


void calculate_spaceship()
{
    if (movement < 0){
        if (spaceship->x_location + movement > 0 ){
            spaceship->x_location -= movement;
        }else {
            spaceship->x_location = 10;
        }
    }else if (movement > 0){
        if (spaceship->x_location + movement < FIELD_WIDTH ){
            spaceship->x_location += movement;
        }else{
            spaceship->x_location = FIELD_WIDTH -20;
        }
    }
    if (shooting && !shot_fired){
        shoot_laser (spaceship);
    }
    
}




int isHit(game_object *laser, game_object *block)
{
    int hit = 0;
    if ((block->lives > 0) && (block->type != laser->type && (block->x_location <= laser->x_location) && block->x_location + block->width >= laser->x_location)){
        switch (laser->type){
            case 1: //enemy laser
                if ((laser->y_location - LASERSPEED < block->y_location) && laser->y_location >= block->y_location) {
                    block->lives -= 1;
                    hit = 1;
                }
                break;
            case 2:
                if ((laser->y_location + LASERSPEED > block->y_location) && laser->y_location <= block->y_location) {
                    block->lives -= 1;
                    hit = 1;
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
        terminate_laser(laser);
        if (spaceship->lives <= 0)
            gameover = 1;
        return 1;
    }
    int i;
    for (i=0; i < NOFBLOCKS; i++){
        if (isHit(laser, &blocks[i])){
            if(blocks[i].lives <= 0) blocks[i].color = BLACK;
            terminate_laser(laser);
            return 1;
        }
    }
    return 0;
}

/***********************************************************
 * Block 3: Putting stuff on the field (painting the field)
 **********************/

//puts a rectangle block on the field
void putBlockOnField(game_object *block)
{
    int i, j;
    for (i=block->x_location; i< (block->x_location + block->width); i++){
        for (j=block->y_location; j<(block->y_location+block->height); j++){
            field[i][j]= block->type;
        }
    }
}

//puts a laser on the field (little cross)
void putLaserOnField(game_object *laser)
{
    int LASERCOLOROFFSET = 3;
    int laserColor = laser->type + LASERCOLOROFFSET;
    field[laser->x_location][laser->y_location]   = laserColor;
    field[laser->x_location-1][laser->y_location] = laserColor;
    field[laser->x_location+1][laser->y_location] = laserColor;
    field[laser->x_location][laser->y_location-1] = laserColor;
    field[laser->x_location][laser->y_location+1] = laserColor;
}

//restart field, may be not the best solution, but the quickest to implement
int generateField()
{
    int i,j;
    for (i=0; i<FIELD_WIDTH; i++){
        for (j=0; j<FIELD_HEIGHT; j++) {
            field[i][j]= 0;
        }
    }
    putBlockOnField(spaceship);
    
    for (i=0; i<NOFBLOCKS ; i++){
        putBlockOnField(&blocks[i]);
    }
    game_object **currentLaser = &lasers->first_laser;
    while (*currentLaser) {
        putLaserOnField(*currentLaser);
        currentLaser = &(*currentLaser)->next;
    }
    return 0;
}

int tick()
{
    calculate_spaceship();
    calculate_blocks();
    game_object **actual_laser = &lasers->first_laser;
    while (*actual_laser){
        calculate_laser(*actual_laser);
        detect_hit(*actual_laser);
        actual_laser = &(*actual_laser)->next;
    }
    
    return generateField();
}


int game_end()
{   //TODO
    //all lasers
//    free (laser);
    free (lasers);
    free (spaceship);
    free (blocks);
    return 0;
}





