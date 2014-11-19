#ifndef ____renderer__
#define ____renderer__

#define WHITE   0xffffff
#define BLACK   0x000000
#define RED     0xff0000
#define GREEN   0x00ff00
#define BLUE    0x0000ff

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FIELD_WIDTH 640
#define FIELD_HEIGHT 480


char screen[FIELD_WIDTH * FIELD_HEIGHT * 3];

void render(int **field);

#endif
