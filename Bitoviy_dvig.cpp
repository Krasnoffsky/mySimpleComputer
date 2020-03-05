#include "mySimpleComputer.hpp"

int main(void)
{
	sc_regInit();
	cout << endl << "-----------------------" << endl;
	sc_regGet(0);
	cout << endl << "-----------------------" << endl;
	sc_regSet(1, true);
	cout << endl << "-----------------------" << endl;
	sc_regGet(0);
	cout << endl << "-----------------------" << endl;
	sc_regSet(3, true);
	cout << endl << "-----------------------" << endl;
	sc_regGet(3);
	cout << endl << "-----------------------" << endl;
	sc_regSet(2, true);
	cout << endl << "-----------------------" << endl;
	sc_regGet(8);
	cout << endl << "-----------------------" << endl;
	sc_regSet(9, true);
	cout << endl << "-----------------------" << endl;
	sc_regSet(2, false);
	cout << endl << "-----------------------" << endl;
	sc_regGet(0);
	cout << endl << "-----------------------" << endl;
	sc_regInit();
	cout << endl << "-----------------------" << endl;
	sc_regGet(0);
}
