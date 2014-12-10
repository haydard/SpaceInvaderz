#ifdef WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

void init_screen(){
    SDL_Init(SDL_INIT_VIDEO);
    // TODO screen = SDL_SetVideoMode(640, 480, 32);

    SDL_WM_SetCaption();
}

int screen(char* pixels){
    return 0;
}
