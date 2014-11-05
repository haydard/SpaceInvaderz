#include <stdlib.h>

#define SPACESHIP	0
#define ENEMY		1
#define LASER_ENEMY	2
#define LASER_SPACESHIP 3
#define BLOCK		4

typedef struct GAMEOBJECT{
	int color;
	int x_location;
	int y_location;
	unsigned char lives;
	unsigned char width;
	unsigned char height;
    	int type;
}game_object;

game_object create_gameobject();
