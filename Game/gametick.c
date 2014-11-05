//
//  game.c
//  
//
//  Created by Julia Heinz(!) on 05.11.14.
//
//
#include <peripheral.h>
#include <gametick.h>
#include <renderer.h>

#define NUMBEROFBLOCKS 30
#define LASERSPEED 5

int running;
int paused;
int field[FIELD_WIDTH][FIELD_HEIGHT];
int movement;
int shot;
int levelcleared;
int gameover;
int change;


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


