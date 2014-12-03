#include <ncurses.h>
#include <unistd.h>

#define FALSE 0


void init_screen(){
	initscr();
	curs_set(FALSE);

}

int screen(char* pixels){

}
