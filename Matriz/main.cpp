/*
AUTOR: Oscar Noe Ortiz Barba
CURSO: Diseño y análisis de algoritmos
PROGRAMA: El algoritmo de Strassen
FECHA: 19/11/2021
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include "matriz.h"

int getReSize(int, int, int);

using namespace std;

int main() {
	srand((unsigned)time(nullptr));

	int a, b, c;
	cout << "Entrada: ";
	cin >> a >> b >> c;

	cout << "Salida:" << endl;
	
	matriz A(a, b, (a * c));
	matriz B(b, c, (a * c));

	A.fillRandom();
	B.fillRandom();

	cout << "Matriz A:" << endl;
	A.printMatriz();
	cout << "Matriz B:" << endl;
	B.printMatriz();

	int m = getReSize(a, b, c);

	A.reSize(m);
	B.reSize(m);

	cout << "Redimensionamiento de A:" << endl;
	A.printMatriz();
	cout << "Redimensionamiento de B:" << endl;
	B.printMatriz();

	matriz C(a, c, 0);

	cout << "Suma:" << endl;
	C.suma(&A, &B);
	C.printMatriz();

	cout << "Resta:" << endl;
	C.resta(&A, &B);
	C.printMatriz();
	
	//cout << "Producto:" << endl;
	//C.multiplica(&A, &B);
	//C.printMatriz(1);

	return 0;
}

int getReSize(int a, int b, int c) {
	int max = 0;
	int v[] = {a, b, c};
	//obtiene el valor mayor de un arreglo
	for (int i = 0; i < 3; i++) if (v[i] > max) max = v[i];

	int n = 0;
	//obtiene el logaritmo base 2 del max
	n = ceilf(log(max) / log(2));
	//eleva 2 a la n para obtener el valor de la redimension
	n = pow(2, n);

	return n;
}