import pickle

class TV():
    def __init__(self,name,starth,startm,endh,endm):
        self.name = name
        self.starth = starth
        self.startm = startm
        self.endh = endh
        self.endm = endm
    
    def outputall(self):
        print(self.name, ' ', self.starth, ':', sep = '', end = '')
        if self.startm == 0:
            print('00 - ', self.endh, ':', sep = '', end = '')
        else:
            print(self.startm, ' - ', self.endh, ':' ,sep = '', end = '')
        if self.endm == 0:
            print('00')
        else: 
            print(self.endm)



def choice():
    orgfile = 'Lab1.2Porg.txt'
    newfile = 'Lab1.2Pnew.txt'
    while True:
        print('Введите 1, чтобы записать в файл список телепередач')
        print('Введите 2, чтобы отобразить список телепередач')
        print('Введите 3, чтобы отобразить длительность каждой передачи')
        print('Введите 4, чтобы создать файл со списком дневных телепередач')
        print('Введите 5, чтобы отобразить список дневных телепередач')
        print('Введите 6, чтобы остановить работу программы')
        n = int(input())
        if n == 1:
            fillin()
        if n == 2:
            outputfile(orgfile)
        if n == 3:
            duration()
        if n == 4:
            daytv()
        if n == 5:
            outputfile(newfile)
        if n == 6:
            break

def fillin():
    f1 = open('Lab1.2Porg.txt', 'wb')
    quant = 0
    quant = int(input('Введите количество телепередач '))
    i = 0
    while i < quant:
        name = input("Введите название телепередачи ")
        starth = int(input("Введите час начала телепередачи "))
        startm = int(input("Введите минуты начала телепередачи "))
        endh = int(input("Введите час окончания телепередачи "))
        endm = int(input("Введите минуты окончания телепередачи "))
        programm = TV(name,starth,startm,endh,endm)
        programm.outputall()
        i+=1
        pickle.dump(programm, f1)
    print('\n')
    f1.close()

def loadall(filename):
    with open(filename, "rb") as f2:
        while True:
            try:
                yield pickle.load(f2)
            except EOFError:
                break

def outputfile(filename):
    programms = loadall(filename)
    for i in programms:
        programm = i
        programm.outputall()
    print('\n')
    
def duration():
    programms = loadall('Lab1.2Porg.txt')
    for i in programms:
        programm = i
        print(programm.name, ' ', end = '')
        minstart = programm.starth * 60 + programm.startm
        minend = programm.endh * 60 + programm.endm
        overall = minend - minstart
        if (overall // 60) > 0:
            if (overall // 60) == 1:
                print('1 час ', end = '')
            elif (overall // 60) <= 3:
                print(overall // 60, ' часа ')
            else:
                print(overall // 60, ' часов ')
        if (overall - ((overall // 60) * 60)) > 0:
            if overall != 60:
                print(overall - ((overall // 60) * 60), ' минут')
        else:
            print('\n')
    print('\n')

def daytv():
    f1 = open('Lab1.2Pnew.txt', 'wb')
    programms = loadall('Lab1.2Porg.txt')
    for i in programms:
        programm = i
        if programm.starth >= 9:
            if programm.starth < 17:
                pickle.dump(programm,f1)
    f1.close()