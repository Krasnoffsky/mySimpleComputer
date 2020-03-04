#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>

using namespace std;

const unsigned char flag_overflow = 0x01;
const unsigned char flag_0 = 0x02;
const unsigned char flag_memoryBorder = 0x08;
const unsigned char flag_tactIgnore = 0x10;
const unsigned char flag_wrongCommand = 0x20;

unsigned char flags = 0;

int memory[100];

int flag_activate(int temp)
{
	if (temp == 1)
	{
		if (flags & flag_overflow) flags &= ~flag_overflow;
		else flags |= flag_overflow;
		return 0;
	} 
	else if (temp == 2)
	{
		if (flags & flag_0) flags &= ~flag_0;
		else flags |= flag_0;
		return 0;
	}
	else if (temp == 3)
	{
		if (flags & flag_memoryBorder) flags &= ~flag_memoryBorder;
		else flags |= flag_memoryBorder;
		return 0;
	}
	else if (temp == 4)
	{
		if (flags & flag_tactIgnore) flags &= ~flag_tactIgnore;
		else flags |= flag_tactIgnore;
		return 0;
	}
	else if (temp == 5)
	{
		if (flags & flag_wrongCommand) flags &= ~flag_wrongCommand;
		else flags |= flag_wrongCommand;
		return 0;
	}
	return 1;
}

void flag_sostoyanie()
{
	if (flags & flag_overflow) cout << "flag_overflow - True" << endl;
	else cout << "flag_overflow - False" << endl;
	
	if (flags & flag_0) cout << "flag_0 - True" << endl;
	else cout << "flag_0 - False" << endl;
	
	if (flags & flag_memoryBorder) cout << "flag_memoryBorder - True" << endl;
	else cout << "flag_memoryBorder - False" << endl;
	
	if (flags & flag_tactIgnore) cout << "flag_tactIgnore - True" << endl;
	else cout << "flag_tactIgnore - False" << endl;
	
	if (flags & flag_wrongCommand) cout << "flag_wrongCommand - True" << endl;
	else cout << "flag_wrongCommand - False" << endl;
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
		if (flags & flag_memoryBorder);
		else flag_activate(3);
		return 1;

	}
	else{

		memory[address] = value;
		return 0;

	}


}

int sc_memoryGet(int address, int *value){

	if ((address < 0) || (address > 99)){

		if (flags & flag_memoryBorder);
		else flag_activate(3);
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
	flags &= ~flag_overflow;
	flags &= ~flag_0;
	flags &= ~flag_memoryBorder;
	flags &= ~flag_tactIgnore;
	flags &= ~flag_wrongCommand;
	return 0;
}

int sc_regSet ( int regist , bool value )
{
	if (regist < 1 || regist > 5)
	{
		cout << "This register does not exist";
		return 1;
	}

 	else if ( regist == 1 )
 	{
 		if (value == true) flags |= flag_overflow;
		else flags &= ~flag_overflow;
	}
 	
	else if ( regist == 2 )
	{
 		if (value == true) flags |= flag_0;
		else flags &= ~flag_0;
	}
	
	else if ( regist == 3 )
	{
 		if (value == true) flags |= flag_memoryBorder;
		else flags &= ~flag_memoryBorder;
	}
	
	else if ( regist == 4 )
	{
 		if (value == true) flags |= flag_tactIgnore;
		else flags &= ~flag_tactIgnore;
	}
	
	else if ( regist == 5 )
	{
 		if (value == true) flags |= flag_wrongCommand;
		else flags &= ~flag_wrongCommand;
	}
	
	return 0;
	
}

int sc_regGet (int regist)
{
	if (regist < 1 || regist > 5)
	{
		cout << "This register does not exist";
	}

 	else if ( regist == 1 )
 	{
 		if (flags & flag_overflow) cout << "flag_overflow - True" << endl;
		else cout << "flag_overflow - False" << endl;
	}
 	
	else if ( regist == 2 )
	{
 		if (flags & flag_0) cout << "flag_0 - True" << endl;
		else cout << "flag_0 - False" << endl;
	}
	
	else if ( regist == 3 )
	{
 		if (flags & flag_memoryBorder) cout << "flag_memoryBorder - True" << endl;
		else cout << "flag_memoryBorder - False" << endl;
	}
	
	else if ( regist == 4 )
	{
 		if (flags & flag_tactIgnore) cout << "flag_tactIgnore - True" << endl;
		else cout << "flag_tactIgnore - False" << endl;
	}
	
	else if ( regist == 5 )
	{
 		if (flags & flag_wrongCommand) cout << "flag_wrongCommand - True" << endl;
		else cout << "flag_wrongCommand - False" << endl;
	}
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
