#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Matrix.h"

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int row = 4, col = 4;

	Matrix <int> matrix(row, col);
	matrix.InputValue();
	matrix.PrintMatrix();
	cout << endl << "-------------------------------------------------" << endl << endl;


	Matrix <int> matrix2(row, col);
	matrix2.InitWithRandValues();
	matrix2.PrintMatrix();
	cout << endl << "-------------------------------------------------" << endl << endl;


	Matrix <int> sum(row, col);
	sum = matrix + matrix2;
	sum.PrintMatrix();
	cout << endl << "-------------------------------------------------" << endl << endl;


	Matrix <int> sub(row, col);
	sub = matrix - matrix2;
	sub.PrintMatrix();
	cout << endl << "-------------------------------------------------" << endl << endl;


	Matrix <int> prod(row, col);
	prod = matrix * matrix2;
	prod.PrintMatrix();
	cout << endl << "-------------------------------------------------" << endl << endl;


	Matrix <int> div(row, col);
	div = matrix / matrix2;
	div.PrintMatrix();
	cout << endl << "-------------------------------------------------" << endl << endl;
	
	
	int min = matrix.FindMin();
	int max = matrix.FindMax();
	matrix.PrintMatrix();
	cout << endl << "-------------------------------------------------" << endl << endl;

	return 0;
}