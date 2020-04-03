#include "mySimpleComputer.hpp"
#include "myTerm.hpp"
#include "myBigChars.hpp"



int main(void){

	mt_clrscr ();
	mt_gotoXY (2 , 0);
	for (int i = 0; i < SIZE; i ++){
		if (i % 10 == 0){
			printf("\n   ");
		}
		printf("+%d  ", memory[i]);
	}

	bc_box(1, 3, 55, 14);
	bc_box(57, 3, 79, 5);
	bc_box(57, 6, 79, 8);
	bc_box(57, 9, 79, 11);
	bc_box(57, 12, 79, 14);
	bc_box(1, 15, 45, 23);
	bc_box(46, 15, 79, 23);
	mt_gotoXY(3, 27);
	printf("Memory");
	mt_gotoXY(3, 63);
	printf("accumulator");
	mt_gotoXY(4, 66);
	printf("+%d", 23);
	mt_gotoXY(6, 60);
	printf("instructionCounter\n");
	mt_gotoXY(7, 66);
	printf("+%d", 23);
	mt_gotoXY(9, 64);
	printf("Operation\n");
	mt_gotoXY(10, 64);
	printf("+%d : %d", 23, 24);
	mt_gotoXY(12, 66);
	printf("Flags\n");
	mt_gotoXY(13, 64);
	printf("O E V M");
	mt_gotoXY(15, 47);
	printf("Keys:");
	mt_gotoXY(16, 47);
	printf("l - load");
	mt_gotoXY(17, 47);
	printf("s - save");
	mt_gotoXY(18, 47);
	printf("r - run");
	mt_gotoXY(19, 47);
	printf("t - step");
	mt_gotoXY(20, 47);
	printf("i - reset");
	mt_gotoXY(21, 47);
	printf("F5 - accumulator");
	mt_gotoXY(22, 47);
	printf("F6 - instructionCounter\n");
	mt_gotoXY(1, 24);
	
	return 0;
}