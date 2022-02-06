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
		cout << "Введите 1 для записи файла" << endl;
		cout << "Введите 2 для прочтения файла" << endl;
		cout << "Введите 3 для изменения всех символов 0 на 1 и наоборот в файле" << endl;
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
	ofstream f1; //Переменная f1 отвечает за запись в файл
	f1.open("Lab1.1C(org).txt"); //Открываем файл для записи
	if (!f1.is_open()) //Проверка открытия файла
	{
		cout << "Файл для записи не удалось открыть" << endl;
	}
	else //Заполнения файла
	{
		cout << "Файл для записи открыт" << endl;
		string text;
		cout << "Введите текст\nДля перехода на новую строку нажмите клавишу \"Enter\"\nДля завершения ввода текста введите \"end\"" << endl;
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
	f1.close(); //Закрываем открытый файл
}

void read()
{
	setlocale(LC_ALL, "rus");
	ifstream f2; //Переменная f2 отвечает за чтения файла
	f2.open("Lab1.1C(org).txt"); //Открываем файл для чтения
	if (!f2.is_open()) //Проверка открытия файла
	{
		cout << "Файл для чтения не удалось открыть" << endl;
	}
	else //Чтение файла
	{
		cout << "Файл для чтения открыт" << endl;
		cout << "Данные файла" << endl;
		char letter;
		while (f2.get(letter))
		{
			cout << letter;
		}
	}
	cout << endl;
	f2.close(); //Закрываем открытый файл
}

void change()
{
	setlocale(LC_ALL, "rus");
	ifstream f2; //Переменная f2 отвечает за чтения изначального файла
	f2.open("Lab1.1C(org).txt"); //Открываем файл для чтения
	if (!f2.is_open()) //Проверка открытия файла
	{
		cout << "Изначальный файл не удалось открыть" << endl;
	}
	else
	{
		ofstream f1; //Переменная f1 отвечает за запись в новый файл
		f1.open("Lab1.1C(new).txt"); //Открываем файл для записи
		if (!f1.is_open()) //Проверка открытия файла
		{
			cout << "Новый файл не удалось открыть" << endl;
		}
		else //Заполнения нового файла
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
	ifstream f2; //Переменная f2 отвечает за чтения файла
	f2.open("Lab1.1C(new).txt"); //Открываем файл для чтения
	if (!f2.is_open()) //Проверка открытия файла
	{
		cout << "Файл для чтения не удалось открыть" << endl;
	}
	else //Чтение файла
	{
		cout << "Файл для чтения открыт" << endl;
		cout << "Данные файла" << endl;
		char letter;
		while (f2.get(letter))
		{
			cout << letter;
		}
	}
	f2.close(); //Закрываем открытый файл
}