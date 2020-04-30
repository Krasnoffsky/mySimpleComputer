#include "mySimpleComputer.hpp"
#include "myTerm.hpp"
#include "myBigChars.hpp"
#include "myReadkey.hpp"
#include "add.h"
#include <iostream>

int input_x = 27;
int input_y = 3;

int mpos_x = 8;
int mpos_y = 56;

int selected_pos = 0;
int accumulator = 0;
using namespace std;

void print_selected()
{
    if(memory[selected_pos] & 16384)
        bc_printbigchar(bc_chars[MINUS], 3, 15, GREEN, BLACK);
    else
        bc_printbigchar(bc_chars[PLUS], 3, 15, GREEN, BLACK);
    unsigned long int comand_num, operand;  
    sc_commandDecode(memory[selected_pos], comand_num, operand);
   
    bc_printbigchar(bc_chars[(comand_num >> 4) & 7], 12, 15, GREEN, BLACK);
    bc_printbigchar(bc_chars[comand_num & 15], 21, 15, GREEN, BLACK);
    bc_printbigchar(bc_chars[(operand >> 4) & 7], 30, 15, GREEN, BLACK);
    bc_printbigchar(bc_chars[operand & 15], 39, 15, GREEN, BLACK);

}

int print_flags()
{
	int flag;
	if(sc_regGet(flag_memoryBorder))
	{
		printf("M");
	}
	if(sc_regGet(flag_overflow))
	{
		printf("P");
	}
	if(sc_regGet(flag_0))
	{
		printf("O");
	}
	if(sc_regGet(flag_tactIgnore))
	{
		printf("T");
	}
	if(sc_regGet(flag_wrongCommand))
	{
		printf("E");
	}

}

int print_memory()
{
	mt_gotoXY(2, 27);
    int comand_num, operand;
    for (int i = 0; i < SIZE; i ++){
		if (i % 10 == 0){
			printf("\n  ");
		}
		//printf("+%d  ", memory[i]);
		cout << "+" << memory[i] << "  ";
	}
	bc_box(1, 2, 62, 13);
	mt_gotoXY(2, 27);
    printf("Memory");
}

int print_term()
{
	bc_box(64, 2, 79, 4);
	bc_box(64, 5, 79, 7);
	bc_box(64, 8, 79, 10);
	bc_box(64, 11, 79, 13);
	bc_box(1, 14, 47, 23);
	bc_box(48, 14, 79, 23);
	
	
	print_memory();
	mt_gotoXY(2, 66);
	printf("accumulator");
	mt_gotoXY(3, 70);
	printf("+%d", accumulator);

	mt_gotoXY(5, 63);
	printf("instructionCounter\n");
	mt_gotoXY(6, 70);
	printf("%d", instructionCounter);

	mt_gotoXY(8, 67);
	printf("Operation\n");
	mt_gotoXY(9, 68);

	mt_gotoXY(11, 69);
	printf("Flags\n");
	mt_gotoXY(12, 70);
	print_flags();

	mt_gotoXY(15, 3);
	print_selected();

	mt_gotoXY(14, 49);
	printf("Keys:");
	mt_gotoXY(15, 49);
	printf("l - load");
	mt_gotoXY(16, 49);
	printf("s - save");
	mt_gotoXY(17, 49);
	printf("r - run");
	mt_gotoXY(18, 49);
	printf("t - step");
	mt_gotoXY(19, 49);
	printf("i - reset");
	mt_gotoXY(20, 49);
	printf("F5 - accumulator");
	mt_gotoXY(21, 49);
	printf("F6 - instructionCounter\n");

	mt_gotoXY(24, 1);
}

int main(){
	
	mt_clrscr();
	sc_regInit();
	sc_memorySet(instructionCounter, 123);

	sc_regSet(flag_memoryBorder, 1);
	sc_regSet(flag_0, 1);
	print_term();
	//rk_mytermregime (0, 0, 1, 0, 1);
	rk_mytermregime (1, 300, 15, 1, 1);
	while (true){

		int key;
		rk_readkey(&key);
		if (key == 83) rk_mytermsave();
		else if (key == 76) rk_mytermrestore();
		else if (key == 27) break;

	}
	
	
	return 0;
}