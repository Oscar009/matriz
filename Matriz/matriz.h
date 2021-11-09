#ifndef matriz_h
#define matriz_h

#include <ctime>
#include <stdlib.h>
#include <iostream>

class matriz
{
	int** cells;
	int rows;
	int columns;

public:
	matriz(int, int);
	~matriz();

	void add(matriz*, matriz*);
	void sub(matriz*, matriz*);
	void mult(matriz*, matriz*);

	int getCell(int, int);
	int getRowsLength();
	int getColumnsLength();
	void fillRandom();
	void reSize(int);
	void printMatriz();
};
#endif