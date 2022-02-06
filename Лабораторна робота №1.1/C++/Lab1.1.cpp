#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

void fillin();
void read();
void change();
void show();

void choice()
{
	setlocale(LC_ALL, "rus");
	int n;
	for (int i = 0;; i++)
	{
		cout << "������� 1 ��� ������ �����" << endl;
		cout << "������� 2 ��� ��������� �����" << endl;
		cout << "������� 3 ��� ��������� ���� �������� 0 �� 1 � �������� � �����" << endl;
		cin >> n;
		if (n == 1)
		{
			fillin();
		}
		else if (n == 2)
		{
			read();
		}
		else if (n == 3)
		{
			change();
			show();
			break;
		}
	}
}

void fillin()
{
	setlocale(LC_ALL, "rus");
	ofstream f1; //���������� f1 �������� �� ������ � ����
	f1.open("Lab1.1C(org).txt"); //��������� ���� ��� ������
	if (!f1.is_open()) //�������� �������� �����
	{
		cout << "���� ��� ������ �� ������� �������" << endl;
	}
	else //���������� �����
	{
		cout << "���� ��� ������ ������" << endl;
		string text;
		cout << "������� �����\n��� �������� �� ����� ������ ������� ������� \"Enter\"\n��� ���������� ����� ������ ������� \"end\"" << endl;
		for (int i = 0;; i++)
		{
			SetConsoleCP(1251);
			text = "";
			getline(cin, text);
			if (text == "end")
			{
				break;
			}
			f1 << text;
			f1 << "\n";
		}
	}
	cout << endl;
	f1.close(); //��������� �������� ����
}

void read()
{
	setlocale(LC_ALL, "rus");
	ifstream f2; //���������� f2 �������� �� ������ �����
	f2.open("Lab1.1C(org).txt"); //��������� ���� ��� ������
	if (!f2.is_open()) //�������� �������� �����
	{
		cout << "���� ��� ������ �� ������� �������" << endl;
	}
	else //������ �����
	{
		cout << "���� ��� ������ ������" << endl;
		cout << "������ �����" << endl;
		char letter;
		while (f2.get(letter))
		{
			cout << letter;
		}
	}
	cout << endl;
	f2.close(); //��������� �������� ����
}

void change()
{
	setlocale(LC_ALL, "rus");
	ifstream f2; //���������� f2 �������� �� ������ ������������ �����
	f2.open("Lab1.1C(org).txt"); //��������� ���� ��� ������
	if (!f2.is_open()) //�������� �������� �����
	{
		cout << "����������� ���� �� ������� �������" << endl;
	}
	else
	{
		ofstream f1; //���������� f1 �������� �� ������ � ����� ����
		f1.open("Lab1.1C(new).txt"); //��������� ���� ��� ������
		if (!f1.is_open()) //�������� �������� �����
		{
			cout << "����� ���� �� ������� �������" << endl;
		}
		else //���������� ������ �����
		{
			char letter;
			while (f2.get(letter))
			{
				if (letter == '1')
				{
					f1 << "0";
				}
				else if (letter == '0')
				{
					f1 << "1";
				}
				else
				{
					f1 << letter;
				}
			}
			f1.close();
		}
	}
	f2.close();
	cout << endl;
}

void show()
{
	setlocale(LC_ALL, "rus");
	ifstream f2; //���������� f2 �������� �� ������ �����
	f2.open("Lab1.1C(new).txt"); //��������� ���� ��� ������
	if (!f2.is_open()) //�������� �������� �����
	{
		cout << "���� ��� ������ �� ������� �������" << endl;
	}
	else //������ �����
	{
		cout << "���� ��� ������ ������" << endl;
		cout << "������ �����" << endl;
		char letter;
		while (f2.get(letter))
		{
			cout << letter;
		}
	}
	f2.close(); //��������� �������� ����
}