#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>

using namespace std;

//#define flag_overflow 1
//#define flag_0 2
//#define flag_memoryBorder 3
//#define flag_tactIgnore 4
//#define flag_wrongCommand 5

int memory[100];

int flag_overflow = 0, flag_0 = 0, flag_memoryBorder = 0, flag_tactIgnore = 0, flag_wrongCommand = 0;




//extern int flag_overflow, flag_0, flag_memoryBorder, flag_tactIgnore, flag_wrongCommand, memory[];

int sc_memoryInit( void ){

	for (int i = 0; i < 99; i++ ){

			memory[i] = 0;

	}

	return 0;

}

int sc_memorySet(int address, int value){

	if ((address < 0) || (address > 99)){

		cout << "Error: out of memory border";
		flag_memoryBorder = 1;
		return 1;

	}
	else{

		memory[address] = value;
		return 0;

	}


}

int sc_memoryGet(int address, int *value){

	if ((address < 0) || (address > 99)){

		flag_memoryBorder = true;
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

	fread( memory , 100 , sizeof(*memory) , rdFile ); //this "function" can be wrong. i it doesn't equate to count of size_t type
	fclose( rdFile );
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

int sc_regSet ( int regist , bool value )
{
	if (regist < 1 || regist > 5)
		{
			
			cout << "This register does not exist";
			return 1;
			
		}

 	else if ( regist == 1 ) flag_overflow = value;
 	
	else if ( regist == 2 ) flag_0 = value;
	
	else if ( regist == 3 ) flag_memoryBorder = value;
	
	else if ( regist == 4 ) flag_tactIgnore = value;
	
	else if ( regist == 5 ) flag_wrongCommand = value;
	
	return 0;
	
}

int sc_regGet (int regist, int &value)
{
		if (regist < 1 || regist > 5)
		{
			
			cout << "This register does not exist";
			
		}

 	else if ( regist == 1 ) value = flag_overflow;
 	
	else if ( regist == 2 ) value = flag_0;
 	
	else if ( regist == 3 ) value = flag_memoryBorder;
 	
	else if ( regist == 4 ) value = flag_tactIgnore;
 	
 	else if ( regist == 5 ) value = flag_wrongCommand;
 	
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

int sc_commandEncode ( int command , int operand , int* value ){ // we neeed to check operand and command and write function for checking it

	int dec = codeHexToDec(command);
	codeDecToBin( dec , value, 7 , 1 );
	dec = codeHexToDec(operand);
	codeDecToBin( dec , value , 14 , 8 );
	return 0;

}

int sc_commandDecode ( int value[] , int* command, int* operand ){ // we neeed to check operand and command and write function for checking it

	
	
	int hex = 0, hex1= 0;
	int k = 1;

	for ( int i = 0 ; i < 7 ; i++ , k++ ){

			hex += value[k] * pow( 2 , i );

			cout << hex <<" ";

	}

	hex /= 2;

	int i = 0;

	cout << "<-<-<-<Cycle starts here>->->->" << endl;

	do {

		hex1 += hex % 16 * pow ( 10 , i );

		i++;

		hex /= 16;

	} while (hex % 16 != 0);

	cout << "<-<-<-<Cycle ends here>->->->" << endl;
	
	*command = hex1;
	
	k= 8;
	hex = 0;

	for ( int i = 0 ; i < 7 ; i++ , k++ ){

			hex += value[k] * pow( 2 , i );

			cout << hex <<" ";

	}

	hex1 = 0;

	//hex /= 2;

	cout << "<-<-<-<Cycle 2 starts here>->->->" << endl;	

	i = 0;

	do {

		hex1 += hex % 16 * pow ( 10 , i );

		i++;

		hex /= 16;

	} while (hex % 16 != 0);

	cout << "<-<-<-<Cycle 2 ends here>->->->" << endl;
	
	*operand = hex1;
	return 0;

}

int sc_commandDecode_demo ( int value[] , int* command){ // we neeed to check operand and command and write function for checking it
	
	int hex = 0, hex1= 0;
	int k = 8;

	for ( int i = 0 ; i < 7 ; i++ , k++ ){

			hex += value[k] * pow( 2 , i );

			cout << "Hex = "<< hex << endl << "i = " << i << endl;

	}


	int i = 0;

	cout << "<-<-<-<Cycle starts here>->->->" << endl;

	do {

		hex1 += hex % 16 * pow ( 10 , i );

		i++;

		hex /= 16;

	} while (hex % 16 != 0);

	cout << "<-<-<-<Cycle ends here>->->->" << endl;
	
	*command = hex1;

	return 0;

}
