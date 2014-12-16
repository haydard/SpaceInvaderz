#ifndef ____objects__
#define ____objects__

#include <stdlib.h>

#define SPACESHIP           0
#define ENEMY               1
#define LASER_ENEMY         2
#define LASER_SPACESHIP     3
#define BLOCK               4


typedef struct _game_object{
	int number;
	int color;  //Black=0; White=1;
	int x_location;
	int y_location;
	unsigned char lives;
	unsigned char width;
	unsigned char height;
    int type;
    struct _game_object *next;
}game_object;

//game_object create_gameobject();


#endif //(__objects__)defined
