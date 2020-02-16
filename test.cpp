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

		cout << i << " ";

		cin >> command[i];

	}

	cout << endl;

	j = 0;

	i = 0;

	// cout << "<-<-<-<-<Error must be here>->->->->" << endl;
	
	k = sc_commandDecode_demo( command , &j);

	cout << "memoryDecode " << k << " " << j << endl;

	return 0;

}
