#include <stdio.h>
#include <stdlib.h>
#include <gametick.h>
#include <unistd.h>

#define GAME_SPEED 1

int running;
int paused;

int main()
{
    //initialize the game;
    running = game_init();
    while (running) {
    	usleep(50000/GAME_SPEED);
        //check for events
        event();
        while (paused)
            continue;
        
        gametick();
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
