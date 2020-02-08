#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
#include "mySimpleComputer.h"

int main( void ){

	int command[15];

	int value = 0;

	int i , j , k;

	char name[10];

	srand(time(NULL));

	sc_memoryInit();

	cout << " memoryInit = " << sc_memoryInit() << endl;

	for ( i = 0 ; i < 100 ; i++ ){

		cout << memory[i] << " ";

	}

	cout << endl;

	for (i = 0 ; i < 100 ; i++ ){


			memory[i] = rand()%1000;

	}

	for ( i = 0 ; i < 100 ; i++ ){

		cout << memory[i] << " ";

	}

	cin >> j;

	k = sc_memorySet( 2 , j)

	cout << "memorySet " << k << " " << memory[2] << endl;

	k = sc_memoryGet( 5 , j );

	cout << "memoryGet " << k << " " << memory[5] << " " << j << endl;

	cin >> name;

	k = sc_memorySave( name );

	cout << "memorySave " << k << endl;

	k = sc_memoryInit();	

	k = sc_memoryLoad( name );

	cout << "memoryLoad " << k << endl;	

	for ( i = 0 ; i < 100 ; i++ ){

		cout << memory[i] << " ";

	}

	k = sc_regInit();

	cout << "regInit " << flag_overflow << " " << flag_0 << " " << flag_memoryBorder << " " << flag_tactIgnore << " " << flag_wrongCommand << endl;

	k = sc_regSet(2 , true);

	cout << " regSet " << k << " " << flag_0 << endl;

	for ( i = 0 ; i < 15 ; i++ ){

		cin >> command[i];

	}

	k = sc_memoryEncode(33 , 59, command);

	cout << "memoryEncode " << k << endl;

	for ( i = 0 ; i < 15 ; i++ ){

		cout << command[i];

	}
	
	k = sc_memoryDecode( command , j , i);

	cout << "memoryDecode " << k << " " <<j << " " << i << endl;

	return 0;

}