
#include "mySimpleComputer.hpp"

int main( void ){

	int command[15];

	int value = 0;

	int i, j, k, s;

	char name[10];

	for ( i = 0 ; i < 15 ; i++ ){

		command[i] = 0;

	}

	srand(time(NULL));
	
	k = sc_memoryInit();

	cout << " memoryInit = " << k << endl;

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

	cout << "Input number ";

	cin >> j;

	cout << "Input what element you want to change ";

	cin >> s;

	k = sc_memorySet( s , j );

	cout << "memorySet " << k << " " << memory[s] << endl;

	cout << "Input number of element, you want to save ";

	cin >> s;

	k = sc_memoryGet( s , &j );

	cout << "memoryGet " << k << " Your wanted element: " << memory[s] << " Saved element :" << j << endl;

	cout << "Input name of file (10 symbols)";

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

	cout << "Input numbers you want to encode ";

	cin >> j >> i;

	k = sc_commandEncode(33 , 59, command);

	cout << "memoryEncode " << k << endl;

	for ( i = 0 ; i < 15 ; i++ ){

		cout << command[i];

	}

	cout << endl;

	cout << "Input binary number you want to decode ";

	for ( i = 0 ; i < 15 ; i++ ){

		cin >> command[i];

	}
	
	k = sc_commandDecode( command , &j , &i);

	cout << "memoryDecode " << k << " " <<j << " " << i << endl;

	return 0;

}
