//gametick.c

//#include gametick.h>
#include <stdlib.h>
#include <stdio.h>


#define LASERSPEED 5
#define GAME_SPEED 1
#define NOFBLOCKS 30
#define LIVES 3
#define FIELD_WIDTH 640
#define FIELD_HEIGHT 480
#define BLOCK_WIDTH 8
#define BLOCK_HEIGHT 4
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SPACESHIP_START_X 550


int field[FIELD_WIDTH][FIELD_HEIGHT];
int movement;
int shot;
int levelcleared;
int gameover;
int change;


//initializing a new game: create field, create blocks, create spaceship.
int game_init(){
    
    //initialise the field
    int i, j;
    for (i = 0; i < FIELD_WIDTH; i++){
        for j = 0; j< FIELD_HEIGHT ; j++){
            FIELD[i][j] = 0;   //field: 0 = blank, 1= block(enemy), 2=spaceship, 3=rock, 4= laser
        }
    }
    //initialisiere blöcke
    game_object blocks[NOFBLOCKS];
    blocks = (game_object*) malloc(NOFBLOCKS*sizeof(game_object));
    
    game_object *block;
    for (i=0; i < NOFBLOCKS; i++){
        
        block.number = i+1;
        block.color = WHITE;
        block.x_location = 20 + (i*20) % FIELD_WIDTH;
        block.y_location = 10 + (i*20/FIELD_WIDTH*10);
        block.lives = 1;
        block.width = BLOCK_WIDTH;
        block.height = BLOCK_HEIGHT;
        block.type = 1;
        blocks[i] = *block;
        //in jeder 20x10 kasten wird ein block erstellen
    }
    
    /* spaceship (TODO: rocks not yet)
     * SIZE: 8x6, Position 550, centered, 3 lives
     *
     */
    game_object *spaceship = malloc(sizeof(game_object));
    spaceship.number = 1;
    spaceship.color= WHITE;
    spaceship.x_location = SPACESHIP_START_X;
    spaceship.y_location = (FIELD_WIDTH - 8)/2;
    spaceship.lives = 3;
    spaceship.width = 8;
    spaceship.height = 6;
    spaceship.type = 2;
 
    return 1;
}

//check different inputs and write the EVENT;
int event()
{
    check_input();
}

//functions to use in the game loop
int calculate_laser(game_object laser)
{
	switch (laser.type)
		case 2:		//enemy laser
			laser.y_location += LASERSPEED;
			break;
		case 3:
			laser.y_location -= LASERSPEED;
			break;
		default
}

int calculate_blocks()
{
    //for start blocks doesnt move
}

int calculate_spaceship()
{
    if (MOVEMENT){
        // calculate the new spot
    }
}

int detect_hit(){
    //for (every laser, check for collision)
        //if collision, do the thing. else do nothing
}


int tick()
{
    sleep(60/GAME_SPEED);
    calculate_spaceship();
    calculate_blocks();
    calculate_laser();
    detect_hit();
render(field);
    // new_positions_of_things();
    // CHANGE = is_changed();
}


int game_end()
{
    //free resources or something like that;
    return 0;
}


