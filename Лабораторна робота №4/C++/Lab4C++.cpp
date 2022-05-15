#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include "Lab4C++.h"
#include <iomanip>
using namespace std;

class TIntNumber
{
public:
	int number;

	TIntNumber() //Конструктор
	{
		number = 1 + rand() % 100;
	}


	void increment()
	{
		number++;
	}

	void decrement()
	{
		number--;
	}

	void ToTen()
	{
		int temp = 0;
		int position = 0;
		string tempnum = to_string(number);
		string num;
		for (int i = int(log10(number)); i > 0; i--)
		{
			num = tempnum[0];
			number = atoi(num.c_str());
			temp += number * pow(2, i);
			position++;
			tempnum.erase(0,1);
		}
		number = temp;
	}
};

class TIntNumber2 : public TIntNumber
{
public:
	TIntNumber2()
	{
		string binary = "";
		do
		{
			if (number % 2)
			{
				binary += '1';
			}
			else
			{
				binary += '0';
			}
			number = number / 2;
		} while (number);
		string binary2 = "";
		for (int i = binary.length(); i > 0; i--)
		{
			binary2 += binary[i - 1];
		}
		number = atoi(binary2.c_str());
	}
};

class TIntNumber16 : public TIntNumber
{
public:
	string number16;
	TIntNumber16()
	{
		int temp = number;
		do
		{
			int r = temp % 16;
			if (r > 9) 
			{ 
				r += (int)'A' - 10; 
			}
			else 
			{ 
				r += (int)'0'; 
			};
			number16 = (char)r + number16;
			temp /= 16;
		} while (temp);
	}
};

void start()
{
	setlocale(LC_ALL, "rus");
	int m, n;
	cout << "Введите количество двоичных чисел ";
	cin >> m;
	cout << "Введите количество шестнадцатеричных чисел ";
	cin >> n;
	TIntNumber2* Arr2 = new TIntNumber2[m];
	TIntNumber16* Arr16 = new TIntNumber16[n];
	for (int i = 0; i < m; i++)
	{
		TIntNumber2 temp;
		Arr2[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		TIntNumber16 temp;
		Arr16[i] = temp;
	}
	outputnum(Arr2, Arr16, m, n);
}

void outputnum(TIntNumber2* Arr2, TIntNumber16* Arr16, int m, int n)
{
	cout << "Двоичные числа" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << setw(10) << Arr2[i].number;
	}
	cout << "\nШестнадцатеричные числа" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << Arr16[i].number16;
	}
	cout << "\nДвоичные числа в десятичной системе" << endl;
	for (int i = 0; i < m; i++)
	{
		Arr2[i].ToTen();
		cout << setw(10) << Arr2[i].number;
	}
	cout << "\nШестнадцатеричные числа в десятичной системе" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << Arr16[i].number;
	}
	change(Arr2, Arr16, m, n);
}

void change(TIntNumber2* Arr2, TIntNumber16* Arr16, int m, int n)
{
	cout << "\n\nЧисла после изменений" << endl;
	cout << "Двоичные числа" << endl;
	int* arrmax = new int[m + n];
	for (int i = 0; i < m; i++)
	{
		Arr2[i].increment();
		arrmax[i] = Arr2[i].number;
		cout << setw(10) << Arr2[i].number;
	}
	cout << "\nШестнадцатеричные числа" << endl;
	int count = m + 1;
	for (int i = 0; i < n; i++)
	{
		Arr16[i].decrement();
		arrmax[count] = Arr16[i].number;
		cout << setw(10) << Arr16[i].number;
		count++;
	}

	int max = 0;
	for (int i = 0; i < m + n; i++)
	{
		if (arrmax[i] > max)
		{
			max = arrmax[i];
		}
	}

	cout << "\nСамое большое число " << max;
}
