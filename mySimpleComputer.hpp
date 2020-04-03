#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
#include <bitset>
#define SIZE 100

using namespace std;

const int flag_overflow = 0;
const int flag_0 = 1;
const int flag_memoryBorder = 2;
const int flag_tactIgnore = 3;
const int flag_wrongCommand = 4;

bitset<5> bits(0x2);
bitset<15> bits_command(0x2);

int memory[SIZE];

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

int sc_commandEncode (int command, int operand)
{
	if ((command == 10) || (command == 11) || (command == 20) || (command == 21) || ((command >= 30) && (command <= 33)) || ((command >= 40) && (command <= 43)) || ((command >= 51) && (command <= 76)))
	{
		bits_command <<= 15; //очищаем
		bits_command.set(7);
		
		bitset<15> temp_bits_command(command);
		bits_command ^= temp_bits_command;
		bits_command <<= 7;
		
		bitset<15> temp_bits_operand(operand);
		bits_command ^= temp_bits_operand;
		
		cout << bits_command;
		
		return 0;
	}
	
	else
	{
		cout << "Error 1:Command doesn't exist" << endl;
		return 1;
	}
}

int sc_commandDecode (unsigned long int &command, unsigned long int &operand)
{ 	
	bitset<15> temp_bits_decode(0);
	
	bits_command <<= 1;
	temp_bits_decode ^= bits_command;
	bits_command >>= 8;
	
	temp_bits_decode <<= 7;
	temp_bits_decode >>= 8;
	
	command = bits_command.to_ulong();
	operand = temp_bits_decode.to_ulong();
	
	return 0;
}
