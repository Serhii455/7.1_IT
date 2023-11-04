#include <iostream>
#include <iomanip>

using namespace std;


void PrintZ(int** Z, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << Z[i][j];
		cout << endl;
	}
	cout << endl;
}


void ValueZ(int** Z, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			Z[i][j] = Low + rand() % (High - Low + 1);;
}


int Numerosity(int** Z, const int rowCount, const int colCount)
{
	int count = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
		{
			if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0))

				count++;

		}
	return count;
}


int Sum(int** Z, const int rowCount, const int colCount)
{
	int sum = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
		{
			if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0))

				sum += Z[i][j];

		}
	return sum;
}


void Change(int** Z, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = Z[j][col1];
		Z[j][col1] = Z[j][col2];
		Z[j][col2] = tmp;
	}
}


void Sort(int** Z, const int rowCount, const int colCount)
{
	for (int j0 = 0; j0 < colCount - 1; j0++)
		for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
		{
			if (Z[0][j1] < Z[0][j1 + 1]
				|| (Z[0][j1] == Z[0][j1 + 1] && Z[1][j1] + Z[1][j1] < Z[1][j1 + 1])){
				Change(Z, j1, j1 + 1, rowCount);
			}
		}
}


void PrintZ_Modificated(int** Z, const int rowCount, const int colCount)
{
	cout << endl;

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0))
				Z[i][j] = 0;
			cout << setw(4) << Z[i][j];
		}

		cout << endl;

		for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
		{
			if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0))
				Z[i][j] = 0;
		}
	}
	
	
	cout << endl;
}


void PrintSortMatrix(int** Z, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << Z[i][j];
		cout << endl;
	}
	cout << endl;
}

int main()
{
	const int rowCount = 9;
	const int colCount = 7;


	int Low = 4;
	int High = 45;
	int col1 = 0;
	int col2 = 1;


	int** Z = new int* [rowCount];


	for (int i = 0; i < rowCount; i++)
		Z[i] = new int[colCount];


	ValueZ(Z, rowCount, colCount, Low, High);


	cout << "Matrix:" << endl;
	PrintZ(Z, rowCount, colCount);
	cout << setw(4) << endl;


	int numerosityResult = Numerosity(Z, rowCount, colCount);
	cout << "Numerosity = " << numerosityResult << endl;


	int sumResult = Sum(Z, rowCount, colCount);
	cout << "Sum = " << sumResult << endl;
	cout << setw(4) << endl;
	cout << setw(4) << endl;


	cout << "Sort Matrix: " << endl;
	PrintSortMatrix(Z, rowCount, colCount);
	cout << setw(4) << endl;


	cout << "Modificated Matrix: " << endl;
	PrintZ_Modificated(Z, rowCount, colCount);
	cout << setw(4) << endl;
	 

	Sort(Z, rowCount, colCount);


	for (int i = 0; i < rowCount; i++)
		delete[] Z[i];
	delete[] Z;
	return 0;
} 