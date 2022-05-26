#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Tree //������
{
private:
	int row;
	string ident;
	Tree* left, * right;
public:
	Tree(int a, string name); //�����������

	~Tree(); //����������
    
	bool existence(Tree* root, int value, string word); //�������� �������� �������� � �����
	Tree* insert(Tree* root, int value, string name); //��������� �������� �� ������
	void treeprint(Tree* root, int level); //����� ������ �� �����
};

bool IdentCheck(string word);
string IdentChange(string word);
void start();