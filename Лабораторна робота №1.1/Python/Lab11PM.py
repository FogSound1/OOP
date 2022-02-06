def choice():
    while True:
        print("Введите 1 для записи файла")
        print("Введите 2 для прочтения файла")
        print("Введите 3 для изменения всех символов 0 на 1 и наоборот в файле")
        n = int(input())
        if n == 1:
           fillin()
        elif n == 2:
           read()
        elif n == 3:
           change()
           show()
           break

def fillin():
    print('\n')
    print("Файл для записи открыт")
    print("Введите текст\nДля перехода на новую строку нажмите клавишу \"Enter\"\nДля завершения ввода текста введите \"end\"")
    text = ''
    row = ''
    file = open('Lab1.1P(org).txt','w')
    while True:
        row = ''
        row = input()
        if row == 'end':
            break
        text += row + '\n'
    file.write(text[:-1])
    file.close
    print('\n')


def read():
    print('\n')
    file = open('Lab1.1P(org).txt')
    print(file.read())
    file.close()
    print('\n')


def change():
    print('\n')
    file1 = open('Lab1.1P(org).txt')
    file2 = open('Lab1.1P(new).txt','w')
    for row in file1:
        for letter in row:
            if letter == '1':
                file2.write('0')
            elif letter == '0':
                file2.write('1')
            else:
                file2.write(letter)
    file1.close()
    file2.close()
    print('\n')

def show():
    file = open('Lab1.1P(new).txt')
    print(file.read())
    file.close()

