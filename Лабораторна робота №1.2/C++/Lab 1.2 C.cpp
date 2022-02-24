#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Lab 1.2 C.h"
using namespace std;

struct TV //���������, ����������� ������������
{
	char name[255];
	int timestarth;
	int timestartm;
	int timeendh;
	int timeendm;
};

void choice() //������� ������ �������� ��� ������
{
	setlocale(LC_ALL, "rus");
	int n;
	char orgfile [256] = "Lab1.2Corg.txt";
	char newfile [256] = "Lab1.2Cnew.txt";
	for (int i = 0;; i++)
	{
		cout << "������� 1, ����� �������� � ���� ������ �����������" << endl;
		cout << "������� 2, ����� ���������� ������ �����������" << endl;
		cout << "������� 3, ����� ���������� ������������ ������ ��������" << endl;
		cout << "������� 4, ����� ������� ���� �� ������� ������� �����������" << endl;
		cout << "������� 5, ����� ���������� ������ ������� �����������" << endl;
		cout << "������� 6, ����� ���������� ������ ���������" << endl;
		cin >> n;
		if (n == 1)
		{
			fillin();
		}
		else if (n == 2)
		{
			outputorg(orgfile);
		}
		else if (n == 3)
		{
			duration();
		}
		else if (n == 4)
		{
			daytv();
		}
		else if (n == 5)
		{
			outputorg(newfile);
		}
		else if (n == 6)
		{
			break;
		}
	}
}

void fillin() //������� ������ ��������� �����
{
	setlocale(LC_ALL, "rus");
	ofstream f1("Lab1.2Corg.txt", ios::binary);
	int quant;
	TV programm;
	cout << "������� ���������� ����������� ";
	cin >> quant;
	for (int i = 0; i < quant; i++)
	{
		cin.ignore();
		cout << "������� �������� ������������ ";
		gets_s(programm.name);
		cout << "������� ��� ������ ������������ ";
		cin >> programm.timestarth;
		cout << "������� ������ ������ ������������ ";
		cin >> programm.timestartm;
		cout << "������� ��� ����� ������������ ";
		cin >> programm.timeendh;
		cout << "������� ������ ����� ������������ ";
		cin >> programm.timeendm;
		f1.write((char*)&programm, sizeof(TV));
	}
	cout << endl;
	f1.close();
}

void outputorg(char name[256]) //������� ������ ��������� �����
{
	setlocale(LC_ALL, "rus");
	TV programm;
	ifstream f2(name, ios::binary);
	cout << "������ �����������:\n";
	while (f2.read((char*)&programm, sizeof(TV)))
	{
		cout << programm.name << " " << programm.timestarth << ":";
		if (programm.timestartm == 0)
		{
			cout << "00" << " - ";
		}
		else
		{
			cout << programm.timestartm << " - ";
		}
		cout << programm.timeendh << ":"; 
		if (programm.timeendm == 0)
		{
			cout << "00" << endl;
		}
		else
		{
			cout << programm.timeendm << endl;
		}
	}
	cout << endl;
	f2.close();
}

void duration() //������� ����������� ������������ ������������
{
	setlocale(LC_ALL, "rus");
	TV programm;
	ifstream f2("Lab1.2Corg.txt", ios::binary);
	cout << "������������ ������ ��������:\n";
	int minstart, minend, overall ,hours;
	while (f2.read((char*)&programm, sizeof(TV)))
	{
		cout << programm.name << " ";
		minstart = programm.timestarth * 60 + programm.timestartm;
		minend = programm.timeendh * 60 + programm.timeendm;
		overall = minend - minstart;
		if ((overall / 60) > 0)
		{
			if ((overall / 60) == 1)
			{
				cout << "1 ��� ";
			}
			else if ((overall / 60) <=3)
			{
				cout << overall / 60 << " ���� ";
			}
			else
			{
				cout << overall / 60 << " ����� ";
			}
		}
		if ((overall - ((overall / 60) *60)) > 0 && overall != 60)
		{
			cout << overall - ((overall / 60) *60) << " �����" << endl;
		}
		else
		{
			cout << endl;
		}
	}
	cout << endl;
	f2.close();
}

void daytv() //������� �������� ����� � �������� ��������������
{
	setlocale(LC_ALL, "rus");
	TV programm;
	ofstream f1("Lab1.2Cnew.txt", ios::binary);
	ifstream f2("Lab1.2Corg.txt", ios::binary);
	while (f2.read((char*)&programm, sizeof(TV)))
	{
		if (programm.timestarth >= 9 && programm.timestarth < 17 )
		{
			f1.write((char*)&programm, sizeof(TV));
		}
	}
	cout << "���� ������" << endl;
	f1.close();
	f2.close();
}