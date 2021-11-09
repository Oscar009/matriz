#include "matriz.h"

matriz::matriz(int _rows, int _columns) {
	cells = new int* [_rows];
	for (int i = 0; i < _rows; i++) {
		cells[i] = new int[_columns];
	}
	rows = _rows;
	columns = _columns;
}

matriz::~matriz() {
	for (int i = 0; i < rows; i++) {
		delete[] cells[i];
	}
	delete[] cells;
}

void matriz::add(matriz* A, matriz* B) { 
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(*(cells + i) + j) = A->getCell(i, j) + B->getCell(i, j);
		}
	}
}

void matriz::sub(matriz* A, matriz* B) { 
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(*(cells + i) + j) = A->getCell(i, j) - B->getCell(i, j);
		}
	}
}

void matriz::mult(matriz* A, matriz* B) {
	for (int i = 0; i < A->getRowsLength(); i++) {
		for (int j = 0; j < B->getColumnsLength(); j++) {
			*(*(cells + i) + j) = 0;
			for (int k = 0; k < B->getRowsLength(); k++) {
				*(*(cells + i) + j) += A->getCell(i, k) * B->getCell(k, j);
			}
		}
	}
}

int matriz::getCell(int i, int j) { return (*(*(cells + i) + j)); }

int matriz::getRowsLength() { return rows; }

int matriz::getColumnsLength() { return columns; }

void matriz::fillRandom() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(*(cells + i)+ j) = rand() % 9 + 0;
		}
	}
}

void matriz::reSize(int x) {

}

void matriz::printMatriz() { 
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << *(*(cells + i) + j) << " ";
		}
		std::cout << "\n";
	}
}