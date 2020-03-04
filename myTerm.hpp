
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

enum colorbash { RED = 1,
				 GREEN = 2,
				 YELLOW = 3,
				 BLUE= 4,
				 PURPLE = 5,
				 AQUA = 6,
				 WHITE = 7 };

int mt_clrscr (void)
{
	cout << "\033[H\033[J" << endl; //+ перемещение курсора cursor_address
	cout << "\033[%i0;0H" << endl;
	return 0;
}

int mt_gotoXY (int x, int y)
{	
	cout << "\033[%i" << x << ";" << y << "H" << endl;	
}

int mt_getscreensize (int * rows, int * cols)
{
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    *rows = w.ws_row;
    *cols = w.ws_col;
    return 0;
}

int mt_setfgcolor (int colors)
{
	if ( 0 < colors < 8 )
{
	cout << "\033[4"<< colors << "m" << endl;
}
	else return 0;
}

int mt_setbgcolor (int color)
{
	if ( 0 < color < 8 )
{
	cout << "\033[3"<< color << "m" << endl; //Тут я их не особо понимаю с цветом, надо тестить
}
	else return 0;
}

void cursor_invisible()
{
	cout << "\033[?25l\033[?1c" << endl;
}

void cursor_visible()
{
	cout << "\033[?25h\033[?8c" << endl;
}