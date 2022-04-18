#include <iostream>
#include <cmath>
#include <ctime>
#include "Lab3.h"
using namespace std;

class Triangle //Класс треугольник 
{
private:
	double a;
	double b;
	double c;
	int type;

public:
	Triangle(int t) //Конструктор для простого треугольника 
	{
		type = t;
		for (int i = 0; ; i++)
		{
			cout << "Введите величину первой стороны ";
			cin >> a;
			cout << "Введите величину второй стороны ";
			cin >> b;
			cout << "Введите величину третьей стороны ";
			cin >> c;
			if (c >= a + b || a >= c + b || b >= c + a)
			{
				cout << "Одна сторона не может быть большей чем сумма двух других, заполните данные еще раз\n";
				continue;
			}
			else
			{
				break;
			}
		}
	}

	Triangle(int t, int o) //Конструктор прямоугольного треугольника
	{
		type = t;
		for (int i = 0; ; i++)
		{
			cout << "Введите величину первого катета треугольника ";
			cin >> a;
			cout << "Введите величину второго катета треугольника ";
			cin >> b;
			cout << "Введите величину гипотенузы треугольника ";
			cin >> c;
			if (pow(a, 2) + pow(b, 2) != pow(c, 2))
			{
				cout << "Сумма квадратов катетов должна быть равной квадрату гипотенузы\n";
			}
			else
			{
				break;
			}
		}
	}

	Triangle(int t, int o, int p) //Конструктор правильного треугольника
	{
		type = t;
		int x;
		cout << "Введите величину сторон треугольника ";
		cin >> x;
		a = x;
		b = x;
		c = x;
	}

	//Геттеры

	double GetA()
	{
		return a;
	}

	double GetB()
	{
		return b;
	}

	double GetC()
	{
		return c;
	}

	double Area() //Метод исчисления площади треугольников
	{
		double result;
		if (type == 1)
		{
			double p;
			p = (a + b + c) / 2;
			result = sqrt(p * (p - a) * (p - b) * (p - c));
			return result;
		}
		if (type == 2)
		{
			result = (a * b) / 2;
			return result;
		}
		if (type == 3)
		{
			result = (a * a * sqrt(3)) / 4;
			return result;
		} 
	}

	//Перегрузки операторов

	Triangle & operator ++()
	{
		this->a++;
		this->b++;
		this->c++;
		return *this;
	}

	Triangle & operator --()
	{
		this->a--;
		this->b--;
		this->c--;
		return *this;
	}

	Triangle& operator += (int value)
	{
		a += value;
		b += value;
		c += value;
		return *this;
	}

	Triangle& operator -= (int value)
	{
		a -= value;
		b -= value;
		c -= value;
		return *this;
	}
};

void start() //Функция начала работы программы
{
	setlocale(LC_ALL, "rus");
	cout << "Введите данные для простого треугольника\n";
	Triangle T1(1);
	cout << "\nВведите данные для прямоугольного треугольника\n";
	Triangle T2(2, 3);
	cout << "\nВведите данные для правильного треугольника\n";
	Triangle T3(3, 3, 4);
	change(T1, T2, T3);
}

void change(Triangle T1, Triangle T2, Triangle T3) //Функция изменения величин сторон треугольников
{
	int n;
	cout << "\nИзначальные величины треугольников\n";
	cout << "\nПервый треугольник\n";
	cout << "Первая сторона " << T1.GetA() << "\tВторая сторона " << T1.GetB() << "\tТретья сторона " << T1.GetC();
	cout << "\nвторой треугольник\n";
	cout << "Первая сторона " << T2.GetA() << "\tВторая сторона " << T2.GetB() << "\tТретья сторона " << T2.GetC();
	cout << "\nТретий треугольник\n";
	cout << "Первая сторона " << T3.GetA() << "\tВторая сторона " << T3.GetB() << "\tТретья сторона " << T3.GetC();

	cout << "\n\nВведите величину на которую стороны третьего треугольника будут увеличены ";
	cin >> n;
	++T1;
	--T2;
	T3 += n;

	cout << "\nНовые величины треугольников\n";
	cout << "\nПервый треугольник\n";
	cout << "Первая сторона " << T1.GetA() << "\tВторая сторона " << T1.GetB() << "\tТретья сторона " << T1.GetC();
	cout << "\nвторой треугольник\n";
	cout << "Первая сторона " << T2.GetA() << "\tВторая сторона " << T2.GetB() << "\tТретья сторона " << T2.GetC();
	cout << "\nТретий треугольник\n";
	cout << "Первая сторона " << T3.GetA() << "\tВторая сторона " << T3.GetB() << "\tТретья сторона " << T3.GetC();
	final(T1, T2, T3);
}

void final(Triangle T1, Triangle T2, Triangle T3) //Функция нахождения плозадей и сравнения их между собой
{
	cout << "\n\nПлощадь первого треугольника равна " << T1.Area();
	cout << "\nПлощадь второго треугольника равна " << T2.Area();
	cout << "\nПлощадь третьего треугольника равна " << T3.Area();
	if (T1.Area() > T2.Area() && T1.Area() > T3.Area())
	{
		cout << "\nПлощадь первого треугольника самая большая";
	}
	else if (T2.Area() > T1.Area() && T2.Area() > T3.Area())
	{
		cout << "\nПлощадь второго треугольника самая большая";
	}
	else
	{
		cout << "\n\nПлощадь третьего треугольника самая большая\n";
	}
}