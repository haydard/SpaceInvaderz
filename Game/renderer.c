#include <renderer.h>


char screen[FIELD_WIDTH * FIELD_HEIGHT * 3];

//simple monochrom color array creator, we have to see where to put the array;
int color_RGB(int c)
{
    if (c){
        return WHITE;
    }else {
        return BLACK;
    }
}

int render(int** field)
{
    //if(change){
        for (i = 0; i < FIELD_WIDTH; i++){
            for j = 0; j< FIELD_HEIGHT ; j++){
                screen[((i*FIELD_WIDTH) + j) * 3] = color_RGB(field[i][j]);
            }
        }
    //}
    //sound
}
