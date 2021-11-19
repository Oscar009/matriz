#ifndef matriz_h
#define matriz_h

#include <ctime>
#include <stdlib.h>
#include <iostream>

class matriz
{
	typedef enum { above, down } height;
	typedef enum { left, right } side;
	int** cells;
	int rows;
	int columns;
	int maxRandom;

public:
	matriz(int, int, int);
	matriz(matriz, int, int);
	~matriz();

	matriz suma(matriz, matriz);
	matriz resta(matriz, matriz);
	matriz multiplica(matriz, matriz);
	matriz strassen(matriz, matriz);

	int getCell(int, int);
	void setCell(int, int, int);
	int getRowsLength();
	int getColumnsLength();
	void fillRandom();
	void reSize(int);
	void printMatriz();

};
#endif