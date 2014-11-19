#include <renderer.h>
#include <gametick.h>


// #include soundlibrary


//#define BYTE_DEPTH 3

#define WHITE   0xffffff
#define BLACK   0x000000
#define RED     0xff0000
#define GREEN   0x00ff00
#define BLUE    0x0000ff

const char screen[FIELD_WIDTH * FIELD_HEIGHT * 3];

//Adress of the pixel array, used by video driver. Somehow to communicate with video driver.
char* MEM_VIDEO = &screen;



//simple monochrom color array creator, we have to see where to put the array;
int color_RGB(int c)
{
    if (c){
        return WHITE;
    }else {
        return BLACK;
    }
}

int render_graphic()
{
    //if(change){
        for (i = 0; i < FIELD_WIDTH; i++){
            for j = 0; j< FIELD_HEIGHT ; j++){
                screen[((i*FIELD_WIDTH) + j) * 3] = color_RGB(field[i][j]);
            }
        }
    //}
}

//render the sound
int render_sound(){
    int soundfile = 0;
    if (!soundfile)
        printf("no sound found!");
}

//bundled rendering function
int render(){
    render_graphic();
    render_sound();
}



