#include <stdio.h>
#include <stdlib.h>
#include "gametick.h"
#include <unistd.h>

#define GAME_SPEED 1

//initialize the game,
int main(int argc, char *argv[])
{
    //initialize the game;
    if (!game_init()){
        printf("initiation error");
        return -1;
    }
    while (!gameover) {
    	usleep(50000/GAME_SPEED);
        //check for events
        get_event();
        while (paused)
            continue;
        tick();
        renderScreen();
    }
    
    //end of game
    int finish = 1;
    finish = game_end();
    if (!finish){
        printf("Thank you for playing!");
    }
    else {printf("Something went wrong during quitting the game");
    }
    return 0;
}

