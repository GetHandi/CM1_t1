// Вариант 4;
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const unsigned char SIZE = 5;

double matrix[SIZE][SIZE + 1] = { {-0.69, -0.04, 0.52, -0.7, 0.53, 0.59},
								  {-0.22, -0.49, -0.96, 0.95, 0.27, 0.81},
								  {0.15, 0.55, 0.33, -0.18, 0.14, 0.93},
								  {0.47, -0.53, 0.0, 0.97, -0.26, 0.52},
								  {0.4, 0.94, -0.41, -0.04, 0.52, -0.74} };



void PrintMatrix(double* matrix, const unsigned char SIZE);


int main()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE + 1; j++) {
			cout << setw(6) << matrix[i][j];
		}
		cout << endl;
	}

	int m = 0;
	for (int k = 0; k < SIZE; k++)
	{
		// проверка на 0;
		if (abs(matrix[k][k] < 0.000001))
		{
			m = k + 1;
			while (abs(matrix[m][k] < 0.000001))
			{
				m = m + 1;
			}
			for (int j = 0; j < SIZE; j++)
			{

			}
		}


		// правило прямоугольника;
		for (int i = k + 1; i < SIZE; i++)
		{
			for (int j = k + 1; j < SIZE + 1; j++)
			{
				matrix[i][j] = (matrix[i][j] * matrix[k][k] - matrix[k][j] * matrix[i][k]) / matrix[k][k];
			}
		}

		// обнуление k-го столбца;
		for (int i = k + 1; i < SIZE; i++)
		{
			matrix[i][k] = 0;
		}

		// деление элементов k-й строки на matrix[k][k];
		for (int j = SIZE; j >= 0; j--)
		{
			matrix[k][j] /= matrix[k][k];
		}

		// вывод матрицы в консоль;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE + 1; j++) {
				cout << setw(9) << matrix[i][j];
			}
			cout << endl;
		}
		cout << endl;



	}


	return 0;
}
