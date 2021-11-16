#include "matriz.h"

matriz::matriz(int _rows, int _columns) {
	cells = new int* [_rows];
	for (int i = 0; i < _rows; i++) {
		cells[i] = new int[_columns];
	}
	rows = _rows;
	columns = _columns;
	rowsReSize = _rows;
	columnsReSize = _columns;
}

matriz::~matriz() {
	for (int i = 0; i < rowsReSize; i++) {
		delete[] cells[i];
	}
	delete[] cells;
}

void matriz::add(matriz* A, matriz* B) { 
	if (A->getColumnsLength() != B->getColumnsLength() || A->getRowsLength() != B->getRowsLength()) {
		std::cout << "No se pueden sumar.\n";
	}
	else {
		for (int i = 0; i < rowsReSize; i++) {
			for (int j = 0; j < columnsReSize; j++) {
				*(*(cells + i) + j) = A->getCell(i, j) + B->getCell(i, j);
			}
		}
	}
}

void matriz::sub(matriz* A, matriz* B) { 
	if (A->getColumnsLength() != B->getColumnsLength() || A->getRowsLength() != B->getRowsLength()) {
		std::cout << "No se pueden restar.\n";
	}
	else {
		for (int i = 0; i < rowsReSize; i++) {
			for (int j = 0; j < columnsReSize; j++) {
				*(*(cells + i) + j) = A->getCell(i, j) - B->getCell(i, j);
			}
		}
	}
}

void matriz::mult(matriz* A, matriz* B) {
	if (A->getColumnsLength() != B->getRowsLength()) {
		std::cout << "No se pueden multiplicar\n";
	}
	else {
		for (int i = 0; i < A->getRowsLength(); i++) {
			for (int j = 0; j < B->getColumnsLength(); j++) {
				*(*(cells + i) + j) = 0;
				for (int k = 0; k < B->getRowsLength(); k++) {
					*(*(cells + i) + j) += A->getCell(i, k) * B->getCell(k, j);
				}
			}
		}
	}
}

int matriz::getCell(int i, int j) { return (*(*(cells + i) + j)); }

int matriz::getRowsLength() { return rowsReSize; }

int matriz::getColumnsLength() { return columnsReSize; }

void matriz::fillRandom() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(*(cells + i)+ j) = rand() % 9 + 1;
		}
	}
}

void matriz::reSize(int x) {
	//inicialización de copia
	int **aux = new int* [rows];
	for (int i = 0; i < rows; i++) {
		aux[i] = new int[columns];
	}
	//copia de datos
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(*(aux + i) + j) = *(*(cells + i) + j);
		}
	}
	//reSize de matriz original
	cells = new int* [x];
	for (int i = 0; i < x; i++) {
		cells[i] = new int[x];
	}
	rowsReSize = columnsReSize = x;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			//vaciado de datos
			if (i < rows && j < columns) {
				*(*(cells + i) + j) = *(*(aux + i) + j);
			}
			//llenar con 0
			else {
				*(*(cells + i) + j) = 0;
			}
		}
	}
}

void matriz::printMatriz() { 
	for (int i = 0; i < rowsReSize; i++) {
		for (int j = 0; j < columnsReSize; j++) {
			std::cout << *(*(cells + i) + j) << "\t";
		}
		std::cout << "\n";
	}
}