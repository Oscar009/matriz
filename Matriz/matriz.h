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
	int rowsBackup;
	int columnsBackup;
	int maxRandom;

public:
	matriz(int, int, int);
	matriz(matriz, int, int);
	~matriz();

	void suma(matriz*, matriz*);
	void resta(matriz*, matriz*);
	void multiplica(matriz*, matriz*);

	int getCell(int, int);
	void setCell(int, int, int);
	int getRowsLength();
	int getColumnsLength();
	void fillRandom();
	void reSize(int);
	void printMatriz(int);
};
#endif