

#include "renderer.h"
#include <stdio.h>
#include "SDL/SDL.h"
#include "gametick.h"


// #include soundlibrary


//#define BYTE_DEPTH 3




//Adress of the pixel array, used by video driver. Somehow to communicate with video driver.
//char* MEM_VIDEO = &screen;



//simple monochrom color array creator, we have to see where to put the array;
int color_RGB(int c)
{
    if (c){
        return WHITE;
    }else {
        return BLACK;

    }
}

void render_graphic(int **field)
{
    //if(change){
	int i,j;
        for (i = 0; i < FIELD_WIDTH; i++){
            for (j = 0; j< FIELD_HEIGHT ; j++){
        //        screen[((i*FIELD_WIDTH) + j) * 3] = color_RGB(field[i][j]);
            }
        }
    //}
}

//render the sound
void render_sound(){
    int soundfile = 0;
    if (!soundfile)
        printf("no sound found!");
}

//bundled rendering function
void render(int **field){
    render_graphic(field);
    render_sound();
}



