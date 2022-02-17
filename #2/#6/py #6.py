import random
import time

def FFF(filename,param):
    
    try:
        stream = open(filename,'r')
    except OSError:
        return -1
    
    
    string = stream.read()
    Arr = list(string)
    
    
    if(len(Arr)<3):
        return -2
    
    cnt = 0

    for k in range(0,len(Arr)):
    
        i = k - cnt
    
        if(Arr[i-2] == ':' and Arr[i-1]=='-' and Arr[i]==')'):
            cnt = cnt + 1
            del Arr[i-1]
    

    ZeroArr = [str(0)] * cnt
        
    
    if(param == 1):
        
        try:
            AnswerFile = open('Res.Data.txt','w')
        except OSError:
            return -1

        AnswerFile.write(''.join(Arr+ZeroArr))
        AnswerFile.close()
        print('\nYou can find the answer in the file Res.Data.txt\n')
        
    
    stream.close()

    return cnt

def ArrMaker():

    RandArr = []
    size = 1000000

    for u in range(size):
        RandArr.append(str(random.randint(-10000,10000)))

    try:
        RandFile = open('RandFile.txt','w')
    except OSError:
        return -1

    RandFile.write(''.join(RandArr))
    RandFile.close()

    
    start_time = time.time()
    
    print('Time spent on a random array:\n')
    print("=== %s seconds ===" % (time.time() - start_time))
    print('\n')

    

def Auto_test1():

    test1 = -1

    try:
        test_file1 = open('test1.txt','w')
    except OSError:
        print('\nFailed to open file.\n')
        return 0

    test_file1.write('iej8judndijd83jd3:-)-)-);:;;_-))_00:;:;_0--')
    test_file1.close()

    test1 = FFF('test1.txt',0)

    if(test1 == 1):
        return 1
    
    return 0


def Auto_test2():

    test2 = -1

    try:
        test_file2 = open('test2.txt','w')
    except OSError:
        print('\nFailed to open file.\n')
        return 0

    test_file2.write(':-):-):-)')
    test_file2.close()

    test2 = FFF('test2.txt',0)
    
    
    if(test2 == 3):
        return 1
    
    return 0


def Core_test():
    if((Auto_test1() * Auto_test2())==1):
        return 1

    return 0


if (Core_test()==1):

    name = input("Enter the name of file you want to read:\n")
    answer = FFF(name,1)

    if(answer == -1):
        print('\nFailed to open file.\n')
        exit()


    if(answer == -2):
        print('\nThere must be at least 3 characters in the sequence.\n')
        exit()

   
    ArrMaker()
    

else:

    print("Something went wrong.")
    print("\nAutotest results:\n")

    if (Auto_test1() == 1):
        print("Autotest #1 - passed.\n")

    else:
        print("Autotest #1 - failed.\n")

    if (Auto_test2() == 1):
        print("Autotest #2 - passed.\n")

    else:
        print("Autotest #2 - failed.\n")

    if (Core_test() == 1):
        print("Core test - passed.\n")

    else:
        print("Core test - failed.\n")








