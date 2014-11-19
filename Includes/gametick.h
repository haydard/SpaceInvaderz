#ifndef ____gametick__
#define ____gametick__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "objects.h"
#include "renderer.h"
#include "objects.h"


#define LASERSPEED 5
#define NOFBLOCKS 30
#define LIVES 3
#define BLOCK_WIDTH 8
#define BLOCK_HEIGHT 4
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SPACESHIP_START_X 550

int game_init();

int event();

int calculate_laser();

int calculate_blocks();

int calculate_spaceship();

int detect_hit();

int gametick();

int game_end();

#endif //(___gametick_) defined.
