#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
#include <bitset>

using namespace std;

const int flag_overflow = 0;
const int flag_0 = 1;
const int flag_memoryBorder = 2;
const int flag_tactIgnore = 3;
const int flag_wrongCommand = 4;

bitset<5> bits(0x2);

int memory[100];

void flag_set(int temp)
{
	if (temp == 1) bits.set(flag_overflow);
	else if (temp == 2) bits.set(flag_0);
	else if (temp == 3) bits.set(flag_memoryBorder);
	else if (temp == 4) bits.set(flag_tactIgnore);
	else if (temp == 5) bits.set(flag_wrongCommand);
}

void flag_reset(int temp)
{
	if (temp == 1) bits.reset(flag_overflow);
	else if (temp == 2) bits.reset(flag_0);
	else if (temp == 3) bits.reset(flag_memoryBorder);
	else if (temp == 4) bits.reset(flag_tactIgnore);
	else if (temp == 5) bits.reset(flag_wrongCommand);
}

void flag_flip(int temp)
{
	if (temp == 1) bits.flip(flag_overflow);
	else if (temp == 2) bits.flip(flag_0);
	else if (temp == 3) bits.flip(flag_memoryBorder);
	else if (temp == 4) bits.flip(flag_tactIgnore);
	else if (temp == 5) bits.flip(flag_wrongCommand);
}

int sc_memoryInit( void ){

	for (int i = 0; i < 99; i++ ){

			memory[i] = 0;

	}

	return 0;

}

int sc_memorySet(int address, int value){

	if ((address < 0) || (address > 99)){

		cout << "Error: out of memory border";
		if (bits.test(flag_memoryBorder) == 1);
		else flag_set(3);
		return 1;

	}
	else{

		memory[address] = value;
		return 0;

	}


}

int sc_memoryGet(int address, int *value){

	if ((address < 0) || (address > 99)){

		if (bits.test(flag_memoryBorder) == 1);
		else flag_set(3);
		cout << "Error: out of memory border";
		return 1;

	}
	else {

		*value = memory[address];
		return 0;

	}

}

int sc_memorySave ( char* filename) {

	FILE* wrtFile = fopen( filename , "wb+" );
	if (wrtFile == NULL)
  	{
    
    	cout << "Error: file does not openned" << endl;
      	return 1;
  	
  	}

	fwrite ( memory , 100 , sizeof(*memory) , wrtFile ); 
	fclose( wrtFile );
	return 0;

}

int sc_memoryLoad ( char* filename ){

	FILE* rdFile = fopen( filename , "rb+" );
	if (rdFile == NULL)
  	{
    	
    	cout << "Error: file does not openned" << endl;
      	return 1;

  	}

	fread( memory , 100 , sizeof(*memory) , rdFile );
	fclose( rdFile );
	return 0;

}

int sc_regInit ( void )
{
	bits <<= 5;
	return 0;
}

int sc_regSet ( int regist , bool value )
{
	if (regist < 1 || regist > 5)
	{
		cout << "This register does not exist";
		return 1;
	}

 	else
	{
		for (int temp = 1; temp < 5; temp++)
		{
			if (temp == regist)
			{
	 			if (value == true) flag_set(temp);
				else flag_reset(temp);
				break;
			}
		}
	}
	return 0;
}

int sc_regGet (int regist)
{
	if (regist < 0 || regist > 5)
	{
		cout << "This register does not exist";
	}
	
	else if (regist == 0)
	{
		cout << endl << "flag_overflow = " << bits.test(flag_overflow) << endl;
		cout << endl << "flag_0 = " << bits.test(flag_0) << endl;
		cout << endl << "flag_memoryBorder = " << bits.test(flag_memoryBorder) << endl;
		cout << endl << "flag_tactIgnore = " << bits.test(flag_tactIgnore) << endl;
		cout << endl << "flag_wrongCommand = " << bits.test(flag_wrongCommand) << endl;
	}
	else if (regist == 1) cout << endl << "flag_overflow = " << bits.test(flag_overflow) << endl;
	else if (regist == 2) cout << endl << "flag_0 = " << bits.test(flag_0) << endl;
	else if (regist == 3) cout << endl << "flag_memoryBorder = " << bits.test(flag_memoryBorder) << endl;
	else if (regist == 4) cout << endl << "flag_tactIgnore = " << bits.test(flag_tactIgnore) << endl;
	else if (regist == 5) cout << endl << "flag_wrongCommand = " << bits.test(flag_wrongCommand) << endl;
}

void codeDecToBin ( int dec , int bin[] , int i , int j ){

	if( i > j ) {
		
		codeDecToBin( dec / 2 , bin , i-1, j );

	}
	
	bin[i] = dec % 2;

}

int codeHexToDec ( int hex){

	return (hex  % 10) + (( hex - (hex % 10)) / 10 ) * 16;

}

int sc_commandEncode ( int command , int operand , int* value ){ 

	int i = 0;

if ((command == 10) || (command == 11) || (command == 20) || (command == 21) || ((command >= 30) && (command <= 33)) || ((command >= 40) && (command <= 43)) || ((command >= 51) && (command <= 76)))


	{

		int dec = codeHexToDec(command);
		codeDecToBin( dec , value, 7 , 1 );
		dec = codeHexToDec(operand);
		codeDecToBin( dec , value , 14 , 8 );
		return 0;

	} else {

		cout << "Error 1:Command doesn't exist" << endl;

		return 1;

	}


	

}

int sc_commandDecode ( int value[] , int* command, int* operand ){ 

	
	
	int hex = 0, hex1= 0;
	int k = 1;
	int i = 0;

	for ( i = 6 ; i >=0 ; i-- , k++ ){

			hex += value[k] * pow( 2 , i );

	}

	int s = 0;

	do {

		hex1 += hex % 16 * pow ( 10 , s );

		s++;

		hex /= 16;

	} while (hex % 16 != 0);

	if ((hex1 == 10) || (hex1 == 11) || (hex1 == 20) || (hex1 == 21) || ((hex1 >= 30) && (hex1 <= 33)) || ((hex1 >= 40) && (hex1 <= 43)) || ((hex1 >= 51) && (hex1 <= 76)))

	{
		
		*command = hex1;
	
	} else {

		cout << "Error 1:Command doesn't exist" << endl;

		return 1;

	}	
	
	k= 8;
	hex = 0;
	for ( i = 6 ; i >=0 ; i-- , k++ ){

			hex += value[k] * pow( 2 , i );

	}

	hex1 = 0;	

	s = 0;

	do {

		hex1 += hex % 16 * pow ( 10 , s );

		s++;

		hex /= 16;

	} while (hex % 16 != 0);

	*operand = hex1;
	return 0;

}
