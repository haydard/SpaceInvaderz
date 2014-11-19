#include <stdio.h>
#include <stdlib.h>
#include "Includes/gametick.h"
#include "Includes/renderer.h"


int running;
int paused;

int main()
{
    //initialize the game;
    running = game_init();
    while (running) {
        //check for events
        event();
        while (paused)
            continue;
        
        tick();
        render();
    }
    
    //end of game
    int finish = 1;
    finish = game_end();
    if (!finish){
        printf("Thank you for playing!");
    }
    else {printf("Something went wrong during quitting the game");
    }
}
