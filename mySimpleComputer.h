#ifndef MSC_H
#define MSC_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
#include "mySimpleComputer.h"
#define 1 flag_overflow
#define 2 flag_0
#define 3 flag_memoryBorder
#define 4 flag_tactIgnore
#define 5 flag_wrongCommand

using namespace std;

int memory [100];

int flag_overflow = 0, flag_0 = 0, flag_memoryBorder = 0, flag_tactIgnore = 0, flag_wrongCommand = 0;

int sc_memoryInit( void ){

	for (int i = 0; i < 99; i++ ){

			memory[i] = 0;

	}

}

int sc_memorySet(int address, int value){

	if ((address < 0) || (address > 99)){

		cout << "Error: out of memory border";
		flag_memoryBorder = 1;
		return 1;

	}
	else{

		memory[adress] = value;
		return 0;

	}


}

int sc_memoryGet(int address, int* value){

	if ((address < 0) || (address > 99)){

		flag_memoryBorder = true;
		cout << "Error: out of memory border";
		return 1;

	}
	else {

		value = memory[adress];
		return 0;

	}

}

int sc_memorySave ( char* filename) {

	FILE* wrtFile = fopen( filename , "wb+" );
	if (wrtFile == NULL)
  	{
    
    	fputs("Error: file does not openned" , stderr);
      	return 1;
  	
  	}

	fwrite ( memory , 100 , sizeof(memory) , wrtFile ); 
	fclose( filename );
	return 0;

}


int sc_memoryLoad ( char* filename ){

	FILE* rdFile = fopen( filename , "rb+" );
	if (rdFile == NULL)
  	{
    	
    	fputs("Error: file does not openned" , stderr);
      	return 1;

  	}

	fread( memory , 100 , sizeof(memory) , filename ); //this "function" can be wrong. i it doesn't equate to count of size_t type
	fclose( filename );
	return 0;

}

int sc_regInit ( void )
{

	flag_overflow = false;
	flag_0 = false;
	flag_memoryBorder = false;
	flag_tactIgnore = false;
	flag_wrongCommand = false;
	return 0;

}

int sc_regSet ( int register , bool value )
{
	if ((register < 1) || (register > 5))
		{
			cout « "This register does not exist";
		}
 	else
	{
		register = value;
	}
}

int sc_commandEncode ( int command , int operand , int* value ){ // we neeed to check operand and command and write function for checking it

	int dec = codeHexToDec(command);
	codeDecToBin( dec , &value, 7 , 1 );
	dec = codeHexToDec(operand);
	codeDecToBin( dec , &value , 14 , 8 );
	return 0;

}

int sc_commandDecode ( int* value , int* command, int* operand ){ // we neeed to check operand and command and write function for checking it

	command = codeBinToHex( value , 1 );
	operand = codeBinToHex( value , 8 );
	return 0;

}

void codeDecToBin ( int dec, int* bin, int i , int j){

	if( i >= j ) {
		codeDecToBin( dec / 2 , bin , i-1, j );
	}
	bin[i] = dec % 2;

}

int codeHexToDec ( int hex){

	return (hex  % 10) + (( hex - (hex % 10)) / 10 ) * 16;

}

int codeBinToHex ( int* bin , int k ){

	int hex = 0;

	for ( int i = 0 ; i < 7 ; i++ , k++ ){

			hex += bin[k] * row( 16 , i );

	}

	return hex;

}

#endif