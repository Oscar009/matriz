#include "matriz.h"

matriz::matriz(int _rows, int _columns, int _maxRandom) {
	cells = new int* [_rows];
	for (int i = 0; i < _rows; i++) {
		cells[i] = new int[_columns];
	}
	rowsBackup = _rows;
	columnsBackup = _columns;
	rows = _rows;
	columns = _columns;
	maxRandom = _maxRandom;
}

matriz::matriz(matriz _src, int _heigth, int _side) {

}

matriz::~matriz() {
	for (int i = 0; i < rows; i++) {
		delete[] cells[i];
	}
	delete[] cells;
}

void matriz::suma(matriz* A, matriz* B) { 
	if (A->getColumnsLength() != B->getColumnsLength() || A->getRowsLength() != B->getRowsLength()) {
		std::cout << "No se pueden sumar.\n";
	}
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				this->setCell(i, j, A->getCell(i, j) + B->getCell(i, j));
			}
		}
	}
}

void matriz::resta(matriz* A, matriz* B) { 
	if (A->getColumnsLength() != B->getColumnsLength() || A->getRowsLength() != B->getRowsLength()) {
		std::cout << "No se pueden restar.\n";
	}
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				this->setCell(i, j, A->getCell(i, j) - B->getCell(i, j));
			}
		}
	}
}

void matriz::multiplica(matriz* A, matriz* B) {
	
}

int matriz::getCell(int i,	int j) { return (*(*(cells + i) + j)); }

void matriz::setCell(int i, int j, int v) { (*(*(cells + i) + j)) = v ; }

int matriz::getRowsLength() { return rows; }

int matriz::getColumnsLength() { return columns; }

void matriz::fillRandom() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			this->setCell(i, j, rand() % (maxRandom + 1));
		}
	}
}

void matriz::reSize(int x) {
	//inicialización de copia
	matriz aux(x, x, 0);
	//copia de datos
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			aux.setCell(i, j, *(*(cells + i) + j));
		}
	}
	//reSize de matriz original
	cells = new int* [x];
	for (int i = 0; i < x; i++) {
		cells[i] = new int[x];
	}
	rows = columns = x;
	for (int i = 0; i < x; i++) {
		for ( int j = 0; j < x; j++) {
			//vaciado de datos
			if (i < rowsBackup && j < columnsBackup) {
				this->setCell(i, j, aux.getCell(i, j));
			}
			//llenar con 0
			else {
				this->setCell(i, j, 0);
			}
		}
	}
}

void matriz::printMatriz(int flag) { 
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << *(*(cells + i) + j) << "\t";
		}
		std::cout << "\n";
	}
}