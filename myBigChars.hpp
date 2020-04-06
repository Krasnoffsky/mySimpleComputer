#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

enum {
	BLACK_1 = 0,
	RED_1 = 1,
	GREEN_1 = 2,
	YELLOW_1 = 3,
	BLUE_1 = 4,
	MAG_1 = 5,
	CYAN_1 = 6,
	WHITE_1 = 7
};

int bc_printA (char * str){
	printf("\033(0%s\033(B", str);
	return 0;
}

int bc_box(int x1, int y1, int x2, int y2){
	struct winsize ws;
	if (!ioctl(1, TIOCGWINSZ, &ws)){
		if (0 < x1 && x2 < ws.ws_col && y1 > 0 && y2 < ws.ws_row){
			printf("\033[%d;%dH\033(0", x1, y1);
			for (int i = x1; i <= x2; i ++){
				printf("\033[%d;%dH─", y1, i);
			}
			printf("\033[%d;%dH┐", y1, x2);
			for (int i = y1 + 1; i <= y2; i ++){
				printf("\033[%d;%dH│", i, x2);
			}
			printf("\033[%d;%dH┘", y2, x2);
			for (int i = y1; i <= y2; i ++){
				printf("\033[%d;%dH│", i, x1);
			}
			printf("\033[%d;%dH┌", y1, x1);
			for (int i = x1; i <= x2 - 1; i ++){
				printf("\033[%d;%dH─", y2, i);
			}
			printf("\033[%d;%dH└", y2, x1);
			printf("\n\033(B");
			return 0;
		} else 
			return -1;
	} else 
		return -1;
}

int bc_printbigchar (long int mas[2], int x, int y, int fg, int bg){
	struct winsize ws;
	if (!ioctl(1, TIOCGWINSZ, &ws)){
		//printf(" +++ ");
		//printf("\n row = %d col = %d", ws.ws_row, ws.ws_col);
		if (0 < x && x <= (ws.ws_col - 9) && y > 0 && y <= (ws.ws_row - 9)){
			//printf(" ))) ");
			printf("\033[%d;%dH\033N\033[3%dm\033[4%dm", y, x, fg, bg);
			int h = 0;
			for (int i = 0; i < 2; i ++){
				long int bit = 31;
				for (int j = 0; j < 4; j ++){
					for (int k = 0; k < 8; k ++){
						if (((mas[i] >> bit) & 1) == 0){
							printf("\033[%d;%dH ", y + h, x + k);
						} else {
							printf("\033[%d;%dH▒", y + h, x + k);
						}
						bit --;
					}
					h ++;
				}
			}
			printf("\n\033[0m\033O");
			return 0;
		} else
			return -1;
	} else 
		return -1;
}

int bc_setbigcharpos (int big[2], int x, int y, int value){
	if (x <= 8 && x > 0 && y <= 8 && y > 0){

		if (value == 0){
			if (y <= 4){
				big[0] = big[0]&(~(1 << 32 - ((y - 1) * 8 + x)));
			} else {
				big[1] = big[1]&(~(1 << 32 - ((y - 1) * 8 + x)));
			}
			return 0;
		} else if (value){
			if (y <= 4){
				big[0] = big[0]|(1 << (32 - ((y - 1) * 8 + x)));
			} else {
				big[1] = big[1]|(1 << (32 - ((y - 1) * 8 + x)));
			}
			return 0;
		} else 
			return -1;
	} else 
		return -1;
}

int bc_getbigcharpos(int big[2], int x, int y, int *value){
	if (x <= 8 && x > 0 && y <= 8 && y > 0){
		int i;
		if (y <= 4){
			i = 0;
		} else {
			i = 1;
		}
		*value = (big[i] >> (32 - ((y - 1) * 8 + x)))&1;
		return 0;
	} else 
		return -1;
}

int bc_bigcharwrite (int fd, int big[2], int count){
	int result = write(fd, (int*)big, count); 
    printf("\nWritten: %d chars\n", result); 

    return 0;
}

int bc_bigcharread(int fd, int big[2], int* count)
{
    *count = read(fd, (int*)big, 2); 
    printf("\nWritten: %d chars\n", *count); 

    return 0; 
}