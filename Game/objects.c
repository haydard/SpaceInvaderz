#include <objects.h>


typedef struct game_object{
    int number;
    int color;
    int x_location;
    int y_location;
    int lives;
    int width;
    int height;
    int type;
}game_object;


/*
 * create_gameobject takes a game_object and fills in the given parameters
 * usually to generate a new game object
 */

/*
void create_gameobject(game_object* gameobject, int number, int color, int x_location, int y_location, int lives, int width, int height, int alignment)
{
    gameobject.number = number;
    gameobject.color = color;
    gameobject.x_location = x_location;
    gameobject.y_location = y_location;
    gameobject.lives = lives;
    gameobject.width = width;
    gameobject.height = height;
    gameobject.type = type;

	return 0;
}
*/






