#include "mySimpleComputer.hpp"

int main (void)
{
	unsigned long int command, operand;
	
	cout << endl << "Vvedite comand: ";
	cin >> command;
	
	cout << endl << "Vvedite operand: ";
	cin >> operand;
	
	sc_commandEncode(command, operand);
	sc_commandDecode(command, operand);
	
	cout << endl << "Command = " << command << endl;
	cout << endl << "Operand = " << operand << endl;
}
