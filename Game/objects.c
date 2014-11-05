#include <objects.h>

game_object create_gameobject(int color, int x_location, int y_location, int lives, int width, int height, int alignment)
{
	game_object* gameobject;
	gameobject = malloc(sizeof(game_object));

    gameobject.color = color;
    gameobject.x_location = x_location;
    gameobject.y_location = y_location;
    gameobject.lives = lives;
    gameobject.width = width;
    gameobject.height = height;
    gameobject.type = type;

	return gameobject;
}


