#include <iostream>
#include <ctime>
#include <iomanip>
#include "Lab 2C++.h"
using namespace std;

class Array
{
private:
    int* arr;
    int size;
public:
    Array(int n, int method)
    {
        size = n;
        arr = new int[size];
        if (method == 1)
        {
            arrgen();
        }
        else
        {
            arrgenman();
        }
    }

    void arrgen()
    {

        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
    }

    void arrgenman()
    {
        for (int i = 0; i < size; i++)
        {
            int n;
            cout << "\nВведите элемент массива номер " << i + 1 << "\t";
            cin >> n;
            arr[i] = n;
        }
        cout << "Массив заполнен\n";
    }

    void output()
    {
        for (int i = 0; i < size; i++)
        {
            cout << setw(10) << arr[i];
        }
    }

    int maxnum()
    {
        int max = arr[0];
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }
};

void operation()
{
    setlocale(LC_ALL, "rus");
    int quant, n;
    int method = 0;
    cout << "Введите количество объектов класса ";
    cin >> quant;
    cout << "Введите размерность массивов ";
    cin >> n;
    while (method != 1 && method != 2)
    {
        cout << "Введите 1, чтобы заполнить массивы автоматически\nВведите 2, чтобы заполнить массивы самостоятельно\n";
        cin >> method;
    }
    execution(quant, n, method);
}

void execution(int quant, int n, int method)
{
    int min = 101;
    int max;
    int arrnumber = 0;
    for (int i = 0; i < quant; i++)
    {
        Array arr(n, method);
        cout << "\nМассив номер " << i + 1 << "\n";
        arr.output();
        max = arr.maxnum();
        if (max < min)
        {
            min = max;
            arrnumber = i;
        }
    }
    cout << "\n\nМассив с самым минимальным максимум - массив номер " << arrnumber + 1 << '\n';
    cout << "Этот элемент равен " << min << endl;
}
