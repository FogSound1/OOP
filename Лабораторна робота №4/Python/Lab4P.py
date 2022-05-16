from random import seed
from random import randint
seed(1)

class TIntNumber():

    def __init__(self):
        self.number = randint(1,100)

    def increment(self):
        self.number += 1

    def decrement(self):
        self.number -= 1

    def ToTen(self):
        temp = 0
        position = 0
        tempnum = str(number)
        num = ''
        i = log10(number)
        while i > 0:
            num = tempnum[0]
            number = int(num)
            temp += number * pow(2, i)
            position += 1
            tempnum = tempnum[1:]
            i-=1
        number = temp

class TIntNumber2(TIntNumber):
    def __init__(self):
        tempnum = randint(1,100)
        self.number = tempnum
        b = ''
        while tempnum > 0:
          b = str(tempnum % 2) + b
          tempnum = tempnum // 2
        self.number2 = b

class TIntNumber16(TIntNumber):
    def __init__(self):
        self.number = randint(1,100)
        tempnum = self.number
        s = ''
        h = '0123456789ABCDEF'
        while tempnum > 0:
          s = h[tempnum % 16] + s
          tempnum = tempnum // 16
        self.number16 = s

def start():
    m = int(input('Введите количество двоичных чисел '))
    n = int(input('Введите количество шестнадцатеричных чисел '))
    list2 = []
    list16 = []

    for i in range(m):
        temp = TIntNumber2()
        list2.append(temp)

    for i in range(n):
        temp = TIntNumber16()
        list16.append(temp)
    outputnum(list2, list16, m, n)

def outputnum(list2, list16, m, n):
    print('Двоичные числа')
    for i in range(m):
        print(list2[i].number2, end = '\t')

    print('\nШестнадцатеричные числа')
    for i in range(n):
        print(list16[i].number16, end = '\t')


    print('\nДвоичные числа в десятичной системе')
    for i in range(m):
        print(list2[i].number, end = '\t')

    print('\nШестнадцатеричные числа в десятичной системе')
    for i in range(n):
        print(list16[i].number, end = '\t')
    change(list2, list16, m, n)


def change(list2, list16, m, n):
    max = 0
    print('\n\nДвоичные числа после изменений')
    for i in range(m):
        list2[i].increment()
        print(list2[i].number, end = '\t')
        if list2[i].number > max:
            max = list2[i].number

    print('\nШестнадцатеричные числа после изменений')
    for i in range(n):
        list16[i].decrement()
        print(list16[i].number, end = '\t')
        if list16[i].number > max:
            max = list16[i].number

    print('\nСамое большое число', max, '\n')


    







