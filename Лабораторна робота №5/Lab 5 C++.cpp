#include <iostream>
#include <fstream>
#include <string>
#include "Lab 5 C++.h"
using namespace std;

Tree::Tree(int a, string name) //Конструктор
{
	row = a;
	ident = name;
	left = nullptr;
	right = nullptr;
}

Tree::~Tree() //Деструктор
{
	if (left)
	{
		delete left;
	}
	if (right)
	{
		delete right;
	}
}

bool Tree::existence(Tree* root, int value, string word) //Перевірка наявності елемента у дереві
{
	if (root == nullptr)
	{
		return false;
	}
	if (root->ident == word)
	{
		return true;
	}
	if (value < root->row)
	{
		return existence(root->left, value, word);
	}
	return existence(root->right, value, word);
}

Tree* Tree::insert(Tree* root, int value, string name) //Додавання елементу до дерева
{
	if (existence(root, value, name))
	{
		return root;
	}
	if (root == nullptr)
	{
		return new Tree(value, name);
	}
	if (value < root->row)
	{
		root->left = insert(root->left, value, name);
	}
	if (value > root->row)
	{
		root->right = insert(root->right, value, name);
	}
	return root;
}

void Tree::treeprint(Tree* root, int level) //Вивод дерева на екран
{
	if (root == nullptr)
	{
		return;
	}
	treeprint(root->left, level + 1);
	for (int i = 0; i < level; i++) cout << "   ";
	if (root->row == 0)
	{
		cout << "Tree:\n" << endl;
	}
	else
	{
		cout << root->row << " " << root->ident << endl;
	}
	treeprint(root->right, level + 1);	
}

bool IdentCheck(string word)
{
	string DataType = "int double long short char bool true unsigned false string void auto float new class struct vector";
	string Additional = "++ + ! -/{}%*?:<<==>>=|| ( ) for namespace &&' 1 2 3 4 5 6 7 8 9 0 .,\" using std; #include <iostream>";
	word = IdentChange(word);
	if (DataType.find(word) != string::npos)
	{
		return false;
	}
	else
	{
		if (Additional.find(word) != string::npos)
		{
			return false;
		}
		else
		{
			return true;;
		}
	}
}

string IdentChange(string word)
{
	if (word.find(";"))
	{
		word = word.substr(0, word.find(';'));
	}
	if (word.find("("))
	{
		word = word.substr(0, word.find('('));
	}
	if (word.find("["))
	{
		word = word.substr(0, word.find('['));
	}
	if (word.find("+"))
	{
		word = word.substr(0, word.find('+'));
	}
	if (word.find("["))
	{
		word = word.substr(0, word.find(']'));
	}
	return word;
}

void start()
{
	setlocale(LC_ALL, "rus");
	string filename = "Lab 5 prog.txt";
	Tree* Root = new Tree(0, " ");
	ifstream f1; //Переменная f1 отвечает за чтения файла
	f1.open(filename); //Открываем файл для чтения
	if (!f1.is_open()) //Проверка открытия файла
	{
		cout << "Файл не удалось открыть" << endl;
	}
	else //Чтение файла
	{
		int rownum = 0;
		string line, word;
		while (getline(f1, line))
		{
			rownum += 1;
			while (line.find(' ') != string::npos)
			{
				while (word != line)
				{
					word = line.substr(0, line.find(' '));
					line = line.substr(line.find(' ') + 1);
					if (IdentCheck(word))
					{
						string wordchange = IdentChange(word);
						Root->insert(Root, rownum, wordchange);
					}
				}
			}
		}
	}
	cout << endl;
	f1.close(); //Закрываем открытый файл
	Root->treeprint(Root, 0);
}