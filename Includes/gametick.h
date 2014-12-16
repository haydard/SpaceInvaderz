#ifndef ____gametick__
#define ____gametick__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "objects.h"
#include "renderer.h"
#include "objects.h"


#define LASERSPEED 3
#define NOFBLOCKS 30
#define LIVES 3
#define BLOCK_WIDTH 8
#define BLOCK_HEIGHT 4
#define SPACESHIP_START_Y 550
//#define SPACESHIP_START_X SCREEN_WIDTH/2
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FIELD_WIDTH 640
#define FIELD_HEIGHT 480

//game variables
int field[FIELD_WIDTH][FIELD_HEIGHT];
int movement;
int shooting;
int gameover;
int paused;


//game methods
int game_init();

int get_event();

int tick();

void renderScreen();

int game_end();

/*
 * bunch of internal methods
 void terminate_laser();
 void calculate_laser();
 void calculate_blocks();

 void calculate_spaceship();

 int detect_hit();

 */


#endif //(___gametick_) defined.
