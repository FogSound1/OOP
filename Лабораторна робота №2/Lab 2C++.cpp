#include <iostream>
#include "Lab 2C++.h"
#include <iomanip>
using namespace std;

class numarr
{
public:
	int size;

	int* arrgenauto(int size)
	{
		int* arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 1 + rand() % 100;
		}
		return arr;
	}
	int* arrgenman(int size)
	{
		int* arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			int n;
			cout << "Введите элемент массива номер " << i + 1 << "\t";
			cin >> n;
			arr[i] = n;
		}
		cout << "Массив заполнен\n";
		return arr;
	}
};

void operation()
{
	setlocale(LC_ALL, "rus");
	int n, size;
	int m = 0;
	cout << "Введите количество объектов класса ";
	cin >> n;
	cout << "Введите размерность массивов ";
	cin >> size;
	while (m != 1 && m != 2)
	{
		cout << "Введите 1, чтобы заполнить массивы самостоятельно\nВведите 2, чтобы заполнить массивы автоматически\n";
		cin >> m;
	}
	fillin(n, m, size);
}

void fillin(int n, int m, int size)
{
	numarr arrnum;
	int** overall = new int*[n];
	if (m == 1)
	{
		for (int i = 0; i < n; i++)
		{
			overall[i] = arrnum.arrgenman(size);
		}
	}
	else if (m == 2)
	{
		for (int i = 0; i < n; i++)
		{
			overall[i] = arrnum.arrgenauto(size);
		}
	}
	outputarr(overall, n, size);
}

void outputarr(int** overall, int n, int size)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nМассив номер " << i + 1 << "\n";
		for (int j = 0; j < size; j++)
		{
			cout << setw(10) << overall[i][j];
		}
	}
	minmax(overall, n, size);
}

void minmax(int** overall, int n, int size)
{
	int max = overall[0][0];
	int min = 101;
	int numbermin = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (overall[i][j] > max)
			{
				max = overall[i][j];
			}
		}
		if (max < min)
		{
			numbermin = i;
			min = max;
		}
	}
	cout << "\n\nМассив с самым минимальным максимум - массив номер " << numbermin + 1 << '\n';
	cout << "Этот элемент равен " << min << endl;
}