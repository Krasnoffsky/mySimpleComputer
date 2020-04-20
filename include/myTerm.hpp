#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>

enum {
	BLACK = 0,
	RED = 1,
	GREEN = 2,
	YELLOW = 3,
	BLUE = 4,
	MAG = 5,
	CYAN = 6,
	WHITE = 7
};

int mt_clrscr (void){
	printf("\033[H\033[J");
	return 0;
}

int mt_getscreensize (int * rows, int * cols){
	struct winsize ws;
	if (!ioctl(1, TIOCGWINSZ, &ws)){
		*rows = ws.ws_row;
		*cols = ws.ws_col;
		return 0;
	} else {
		return -1;
	}
}

int mt_gotoXY (int x, int y){
	int row;
	int col;
	mt_getscreensize(&col, &row);
	if (((0 <= x) && ( x <= col))&&((0 <= y) && (y <= row)))
	{
		printf("\033[%d;%dH", x, y);
		return 0;
	}
	else
	{
		return -1;
	} 
}

int mt_setfgcolor (int colors){
	printf("\033[3%dm", colors);
	return 0;
}

int mt_setbgcolor (int colors){
	printf("\033[4%dm", colors);
	return 0;
}