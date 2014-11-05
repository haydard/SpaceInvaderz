#include <gametick.h>
#include <time.h>

int game_init(){
    
    //initialise the field
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
    //spaceship, rocks
}

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
