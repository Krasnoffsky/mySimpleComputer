#include "myTerm.hpp"
#include <iostream>

int main( void ){

	int r, c;

	std::cout << "Start test" << endl;
	std::cout << "Want to see a magic?" << endl;
	getchar();
	mt_setbgcolor(RED);
	std::cout << "Look! It's red!" << endl;
	mt_setfgcolor(GREEN);
	std::cout << "Look! The background now green!" << endl;
	std::cout << "Continue?" << endl;
	getchar();
	cursor_invisible();
	std::cout << "Your cursor now invisible!" << endl;
	getchar();
	cursor_visible();
	std::cout << "It became visible again" << endl;
	std::cout << "Continue?" << endl;
	mt_getscreensize(&r, &c);
 	std::cout << "Rows = " << r << endl << "Cols = "<< c << endl;
 	std::cout << "Now I'm gonna move your cursor" << endl;
 	mt_gotoXY (20, 20);
 	std::cout << "Done!" << endl;
 	std::cout << "Press something to clean screen and complete" << endl;
 	getchar();
 	mt_clrscr();
	return 0;

}
