#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>

using namespace std;

int memory[100];

int flag_overflow = 0, flag_0 = 0, flag_memoryBorder = 0, flag_tactIgnore = 0, flag_wrongCommand = 0;

int sc_memoryInit( void );
int sc_memorySet( int, int );
int sc_memoryGet( int, int* );
int sc_memorySave ( char*);
int sc_memoryLoad ( char* );
int sc_regInit ( void );
int sc_regSet ( int , bool );
int sc_regGet ( int , int );
int sc_commandEncode ( int , int , int* );
int sc_commandDecode ( int[] , int*, int* );
void codeDecToBin ( int, int*, int  , int );
int codeHexToDec ( int );
int codeBinToHex ( int[], int );

#endif
