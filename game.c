//
//  game.c
//  
//
//  Created by Julia Heinz(!) on 05.11.14.
//
//

#include <stdio.h>
#include <time.h>

#define MEM_VIDEO_OUTPUT

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED   0xFF0000
#define GREEN 0x00FF00
#define BLUE  0x0000FF

#define FIELD_WIDTH 640
#define FIELD_HEIGHT 480
#define SCREEN_WIDTH
#define SCREEN_HEIGHT

#define NUMBEROFBLOCKS 30

int RUNNING;
int PAUSED;
int SCREEN[FIELD_WIDTH * FIELD_HEIGHT * 3];  //eindimensionaler (pixel)array
int FIELD[FIELD_WIDTH][FIELD_HEIGHT]; //char geht auch
int MOVEMENT;
char SHOT; //laser shot or not
char LEVELCLEARED;
char GAMEOVER;
char CHANGE;
//or int STATUS: 1= Game Over, 2: LEVEL CLEARED, 3: EPIC FAILURE

enum EVENT{
    SHOT_FIRED;
    JOYSTICK_MOVED;
    PAUSE;
    //and so on;
}

int game_init(){
    
    //initialise the field
    &SCREEN = MEM_VIDEO_OUTPUT;
    
    int i, j;
    for (i = 0; i < FIELD_WIDTH; i++){
        for j = 0; j< FIELD_HEIGHT ; j++){
            FIELD[i][j] = 0;   //field: 0 = blank, 1= block(enemy), 2=spaceship, 3=rock, 4= laser
        }
    }
    //initialisiere blöcke
    for (i=0; i<30; i++){
        //in jeder 20x10 kasten ein block erstellen
    }
    //laser off;
    SHOT = 0;
    
    //spaceship, rocks
}


//check different inputs and write the EVENT;
EVENT event()
{
    check_input();
}

//functions to use in the game loop
int calculate_laser(LASER)
{
    if (LASER->exist){
        if (LASER->alignment){
            LASER->x_location--;
        } else{
            LASER->x_location++;
        }}
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

int loop()
{
    calculate_spaceship();
    calculate_blocks();
    calculate_laser();
    detect_hit();
    // new_positions_of_things();
    // CHANGE = is_changed();
}

//simple monochrom color array creator, we have to see where to put the array;
int color_RGB(int c)
{
    if (c){
        return WHITE;
    }else {
        return BLACK;
    }
}

int render()
{
    //if(change){
        for (i = 0; i < FIELD_WIDTH; i++){
            for j = 0; j< FIELD_HEIGHT ; j++){
                SCREEN[((i*FIELD_WIDTH) + j) * 3] = color_RGB(FIELD[i][j]);
            }
        }
    //}
    //sound
}


int game_end()
{
    //free resources or something like that;
    return 0;
}

/*
 *main file of our game
 */

int main()
{
    //initialize the game;
    game_init();
    while (RUNNING) {
        event();
        while (!PAUSED){
            loop();
            render();
    
        }
    }
    //end of game
    int finish = game_end();
    if (!finish){
        printf("Thank you for playing!");
    }
    else {printf("Something went wrong during quitting");
    }
}

/*
 *Below the structures we need in game:
 * blocks for the beginning
 */

game_object create_gameobject(int color, int x_location, int y_location, int lives, int width, int height, int alignment)
{
    game_object->COLOR = color;
    game_object->x_location = x_location;
    game_object->y_location = y_location;
    game_object->lives = lives;
    game_object->width = width;
    game_object->height = height;
    game_object->alignment = alignment;
}
typedef struct GAMEOBJECT{
    int COLOR;
    int x_location;
    int y_location;
    int lives;
    int width;
    int height;
    // char* name;
    int alignment; //enemy, friendly, neutral
}game_object;
/*
struct ENEMY_BLOCK{
    int COLOR;
    location;
    int alive;
    int width;
    int height;
}

struct SPACESHIP{
    int COLOR;
    location;
    int lives;
    int width;
    int height;
};
*/
typedef struct LASER{
    int exist;
    int alignment;
    int COLOR;
    int x_location;
    int y_location;
}laser;
    
/*some functions probably needed
 *  int occupies(Object);
 *  int detect_hit(GAMEOBJECT block, LASER laser);
 *  int check_input(A, B, C);
 *          &A -> joystick
 *          &B -> fire_button
 *          &C -> game_paused
 */