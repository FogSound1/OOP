#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Tree //Дерево
{
private:
	int row;
	string ident;
	Tree* left, * right;
public:
	Tree(int a, string name); //Конструктор

	~Tree(); //Деструктор
    
	bool existence(Tree* root, int value, string word); //Перевірка наявності елемента у дереві
	Tree* insert(Tree* root, int value, string name); //Додавання елементу до дерева
	void treeprint(Tree* root, int level); //Вивод дерева на екран
};

bool IdentCheck(string word);
string IdentChange(string word);
void start();