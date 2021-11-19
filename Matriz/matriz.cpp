#include "matriz.h"

matriz::matriz(int _rows, int _columns, int _maxRandom) {
	cells = new int* [_rows];
	for (int i = 0; i < _rows; i++) {
		cells[i] = new int[_columns];
	}
	rows = _rows;
	columns = _columns;
	maxRandom = _maxRandom;
}

matriz::matriz(matriz _src, int _heigth, int _side) {
	int aux = _src.getColumnsLength() / 2;
	cells = new int* [aux];
	for (int i = 0; i < aux; i++) {
		cells[i] = new int[aux];
	}
	rows = aux;
	columns = aux;
	maxRandom = 0;

	if (_heigth == above && _side == left) {
		for (int i = 0; i < aux; i++) {
			for (int j = 0; j < aux ; j++) {
				setCell(i, j, _src.getCell(i, j));
			}
		}
	}
	else if(_heigth == above && _side == right) {
		int i1 = 0;
		for (int i = 0; i < (aux); i++) {
			int j1 = 0;
			for (int j = aux; j < (aux*2); j++) {
				setCell(i1, j1, _src.getCell(i, j));
				j1++;
			}
			i1++;
		}
	}
	else if(_heigth == down && _side == left) {
		int i1 = 0;
		for (int i = aux; i < (aux * 2); i++) {
			int j1 = 0;
			for (int j = 0; j < aux; j++) {
				setCell(i1, j1, _src.getCell(i, j));
				j1++;
			}
			i1++;
		}
	}
	else if(_heigth == down && _side == right){
		int i1 = 0;
		for (int i = aux; i < (aux * 2); i++) {
			int j1 = 0;
			for (int j = aux; j < (aux * 2); j++) {
				setCell(i1, j1, _src.getCell(i, j));
				j1++;
			}
			i1++;
		}
	}
}

matriz::~matriz() {
	/*for (int i = 0; i < rows; i++) {
		delete[] cells[i];
	}
	delete[] cells;*/
}

matriz matriz::suma(matriz A, matriz B) { 
	matriz aux(A.getColumnsLength(), B.getColumnsLength(), 0);
	if (A.getColumnsLength() != B.getColumnsLength() || A.getRowsLength() != B.getRowsLength()) {
		std::cout << "No se pueden sumar.\n";
	}
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				aux.setCell(i, j, A.getCell(i, j) + B.getCell(i, j));
			}
		}
	}
	return aux;
}

matriz matriz::resta(matriz A, matriz B) { 
	matriz aux(A.getColumnsLength(), B.getColumnsLength(), 0);
	if (A.getColumnsLength() != B.getColumnsLength() || A.getRowsLength() != B.getRowsLength()) {
		std::cout << "No se pueden restar.\n";
	}
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				aux.setCell(i, j, A.getCell(i, j) - B.getCell(i, j));
			}
		}
	}
	return aux;
}

matriz matriz::multiplica(matriz A, matriz B) {
	matriz aux(A.getColumnsLength(), B.getColumnsLength(), 0);
	if (A.getColumnsLength() != B.getRowsLength()) {
		std::cout << "No se pueden multiplicar.\n";
	}
	else {
		for (int i = 0; i < A.getRowsLength(); i++) {
			for (int j = 0; j < B.getColumnsLength(); j++) {
				aux.setCell(i, j, 0);
				for (int k = 0; k < A.getRowsLength(); k++) {
					aux.setCell(i, j, aux.getCell(i, j) + (A.getCell(i, k) * B.getCell(k, j)));
				}
			}
		}
	}
	return aux;
}

matriz matriz::strassen(matriz A, matriz B) {
	if (A.getColumnsLength() <= 2) return multiplica(A, B);
	else {
		matriz a(A, 0, 0);
		matriz b(A, 0, 1);
		matriz c(A, 1, 0);
		matriz d(A, 1, 1);
		matriz e(B, 0, 0);
		matriz f(B, 0, 1);
		matriz g(B, 1, 0);
		matriz h(B, 1, 1);

		std::cout << std::endl;
		a.printMatriz();
		std::cout << std::endl;
		b.printMatriz();
		std::cout << std::endl;
		c.printMatriz();
		std::cout << std::endl;
		d.printMatriz();

		//matriz p1 = p1.strassen(p1.suma(a, d), p1.suma(e, h));
		//return p1;
		return multiplica(A, B);
	}
}

int matriz::getCell(int i,	int j) { return (*(*(cells + i) + j)); }

void matriz::setCell(int i, int j, int v) { (*(*(cells + i) + j)) = v ; }

int matriz::getRowsLength() { return rows; }

int matriz::getColumnsLength() { return columns; }

void matriz::fillRandom() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			setCell(i, j, rand() % (maxRandom + 1));
		}
	}
}

void matriz::reSize(int x) {
	//inicialización de copia
	matriz aux(x, x, 0);
	//copia de datos
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			aux.setCell(i, j, getCell(i, j));
		}
	}
	//reSize de matriz original
	cells = new int* [x];
	for (int i = 0; i < x; i++) {
		cells[i] = new int[x];
	}
	for (int i = 0; i < x; i++) {
		for ( int j = 0; j < x; j++) {
			//vaciado de datos
			if (i < rows && j < columns) {
				setCell(i, j, aux.getCell(i, j));
			}
			//llenar con 0
			else {
				setCell(i, j, 0);
			}
		}
	}
	rows = columns = x;
}

void matriz::printMatriz() { 
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << getCell(i, j) << "\t";
		}
		std::cout << "\n";
	}
}