#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Lab 1.2 C.h"
using namespace std;

struct TV //Структура, описывающая телепередачу
{
	char name[255];
	int timestarth;
	int timestartm;
	int timeendh;
	int timeendm;
};

void choice() //Функция выбора действия над файлом
{
	setlocale(LC_ALL, "rus");
	int n;
	char orgfile [256] = "Lab1.2Corg.txt";
	char newfile [256] = "Lab1.2Cnew.txt";
	for (int i = 0;; i++)
	{
		cout << "Введите 1, чтобы записать в файл список телепередач" << endl;
		cout << "Введите 2, чтобы отобразить список телепередач" << endl;
		cout << "Введите 3, чтобы отобразить длительность каждой передачи" << endl;
		cout << "Введите 4, чтобы создать файл со списком дневных телепередач" << endl;
		cout << "Введите 5, чтобы отобразить список дневных телепередач" << endl;
		cout << "Введите 6, чтобы остановить работу программы" << endl;
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

void fillin() //Функция записи основного файла
{
	setlocale(LC_ALL, "rus");
	ofstream f1("Lab1.2Corg.txt", ios::binary);
	int quant;
	TV programm;
	cout << "Введите количество телепередач ";
	cin >> quant;
	for (int i = 0; i < quant; i++)
	{
		cin.ignore();
		cout << "Введите название телепередачи ";
		gets_s(programm.name);
		cout << "Введите час начала телепередачи ";
		cin >> programm.timestarth;
		cout << "Введите минуты начала телепередачи ";
		cin >> programm.timestartm;
		cout << "Введите час конца телепередачи ";
		cin >> programm.timeendh;
		cout << "Введите минуты конца телепередачи ";
		cin >> programm.timeendm;
		f1.write((char*)&programm, sizeof(TV));
	}
	cout << endl;
	f1.close();
}

void outputorg(char name[256]) //Функция вывода основного файла
{
	setlocale(LC_ALL, "rus");
	TV programm;
	ifstream f2(name, ios::binary);
	cout << "Список телепередач:\n";
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

void duration() //Функция определения длительности телепередачи
{
	setlocale(LC_ALL, "rus");
	TV programm;
	ifstream f2("Lab1.2Corg.txt", ios::binary);
	cout << "Длительность каждой передачи:\n";
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
				cout << "1 час ";
			}
			else if ((overall / 60) <=3)
			{
				cout << overall / 60 << " часа ";
			}
			else
			{
				cout << overall / 60 << " часов ";
			}
		}
		if ((overall - ((overall / 60) *60)) > 0 && overall != 60)
		{
			cout << overall - ((overall / 60) *60) << " минут" << endl;
		}
		else
		{
			cout << endl;
		}
	}
	cout << endl;
	f2.close();
}

void daytv() //Функция создания файла с дневными телепередачами
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
	cout << "Файл создан" << endl;
	f1.close();
	f2.close();
}