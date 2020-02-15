#include "mySimpleComputer.hpp"
#include <iostream>

using namespace std;

int main( void ){

	int command[15];

	int value = 0;

	int i , j , k , s;

	char name[10];

	srand(time(NULL));
	

	cin >> j;
	cin >> s;

	k = sc_commandEncode(j , s, command);

	cout << "memoryEncode " << k << endl;

	for ( i = 0 ; i < 15 ; i++ ){

		cout << command[i];

	}

	cout << endl;

	for ( i = 0 ; i < 15 ; i++ ){

		cin >> command[i];

		cout << i << " ";

	}

	cout << endl;

	j = 0;
	i = 0;
	
	k = sc_commandDecode( command , &j , &i);

	cout << "memoryDecode " << k << " " <<j << " " << i << endl;

	return 0;

}
