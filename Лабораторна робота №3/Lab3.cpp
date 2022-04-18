#include <iostream>
#include <cmath>
#include <ctime>
#include "Lab3.h"
using namespace std;

class Triangle //����� ����������� 
{
private:
	double a;
	double b;
	double c;
	int type;

public:
	Triangle(int t) //����������� ��� �������� ������������ 
	{
		type = t;
		for (int i = 0; ; i++)
		{
			cout << "������� �������� ������ ������� ";
			cin >> a;
			cout << "������� �������� ������ ������� ";
			cin >> b;
			cout << "������� �������� ������� ������� ";
			cin >> c;
			if (c >= a + b || a >= c + b || b >= c + a)
			{
				cout << "���� ������� �� ����� ���� ������� ��� ����� ���� ������, ��������� ������ ��� ���\n";
				continue;
			}
			else
			{
				break;
			}
		}
	}

	Triangle(int t, int o) //����������� �������������� ������������
	{
		type = t;
		for (int i = 0; ; i++)
		{
			cout << "������� �������� ������� ������ ������������ ";
			cin >> a;
			cout << "������� �������� ������� ������ ������������ ";
			cin >> b;
			cout << "������� �������� ���������� ������������ ";
			cin >> c;
			if (pow(a, 2) + pow(b, 2) != pow(c, 2))
			{
				cout << "����� ��������� ������� ������ ���� ������ �������� ����������\n";
			}
			else
			{
				break;
			}
		}
	}

	Triangle(int t, int o, int p) //����������� ����������� ������������
	{
		type = t;
		int x;
		cout << "������� �������� ������ ������������ ";
		cin >> x;
		a = x;
		b = x;
		c = x;
	}

	//�������

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

	double Area() //����� ���������� ������� �������������
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

	//���������� ����������

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

void start() //������� ������ ������ ���������
{
	setlocale(LC_ALL, "rus");
	cout << "������� ������ ��� �������� ������������\n";
	Triangle T1(1);
	cout << "\n������� ������ ��� �������������� ������������\n";
	Triangle T2(2, 3);
	cout << "\n������� ������ ��� ����������� ������������\n";
	Triangle T3(3, 3, 4);
	change(T1, T2, T3);
}

void change(Triangle T1, Triangle T2, Triangle T3) //������� ��������� ������� ������ �������������
{
	int n;
	cout << "\n����������� �������� �������������\n";
	cout << "\n������ �����������\n";
	cout << "������ ������� " << T1.GetA() << "\t������ ������� " << T1.GetB() << "\t������ ������� " << T1.GetC();
	cout << "\n������ �����������\n";
	cout << "������ ������� " << T2.GetA() << "\t������ ������� " << T2.GetB() << "\t������ ������� " << T2.GetC();
	cout << "\n������ �����������\n";
	cout << "������ ������� " << T3.GetA() << "\t������ ������� " << T3.GetB() << "\t������ ������� " << T3.GetC();

	cout << "\n\n������� �������� �� ������� ������� �������� ������������ ����� ��������� ";
	cin >> n;
	++T1;
	--T2;
	T3 += n;

	cout << "\n����� �������� �������������\n";
	cout << "\n������ �����������\n";
	cout << "������ ������� " << T1.GetA() << "\t������ ������� " << T1.GetB() << "\t������ ������� " << T1.GetC();
	cout << "\n������ �����������\n";
	cout << "������ ������� " << T2.GetA() << "\t������ ������� " << T2.GetB() << "\t������ ������� " << T2.GetC();
	cout << "\n������ �����������\n";
	cout << "������ ������� " << T3.GetA() << "\t������ ������� " << T3.GetB() << "\t������ ������� " << T3.GetC();
	final(T1, T2, T3);
}

void final(Triangle T1, Triangle T2, Triangle T3) //������� ���������� �������� � ��������� �� ����� �����
{
	cout << "\n\n������� ������� ������������ ����� " << T1.Area();
	cout << "\n������� ������� ������������ ����� " << T2.Area();
	cout << "\n������� �������� ������������ ����� " << T3.Area();
	if (T1.Area() > T2.Area() && T1.Area() > T3.Area())
	{
		cout << "\n������� ������� ������������ ����� �������";
	}
	else if (T2.Area() > T1.Area() && T2.Area() > T3.Area())
	{
		cout << "\n������� ������� ������������ ����� �������";
	}
	else
	{
		cout << "\n\n������� �������� ������������ ����� �������\n";
	}
}