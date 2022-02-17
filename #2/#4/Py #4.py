def FFF(filename):
    try:
        file = open(filename,'r')
    except OSError:
        print('\nFailed to open file.\n')
        return -1

    D = -1
    sum_of_squares = 0
    sum_of_prime = 0
    n = 0
    M = 0
    intermadiate = 0
    Mega = 0
   
    for line in file:
        for i in line.split():
            try:
                sum_of_squares = sum_of_squares + (int(i)) ** 2
                sum_of_prime = sum_of_prime + int(i)
                n = n + 1
            except ValueError:
                print('\nUncorrect value.\n')
                return -1

    if(n==0):
        return -2

    M  = sum_of_prime/n
    Mega = n*(M ** 2)
    
    intermediate = sum_of_squares + Mega -2*M*sum_of_prime

    D = (1/n)*intermediate

    file.close()

    return D


def Auto_test1():
    
    test1 = 0
    try:
        test_file1 = open('test1.txt', 'w')
    except OSError:
        print('\nFailed to open file.\n')
        return -1

    test_file1.write('5 5 5 5 5')
    test_file1.close()

    test1 = FFF("test1.txt")

    if (test1 == 0):
        return 1

    else:
        return 0


def Auto_test2():

    test2 = 0
    try:
        test_file2 = open('test2.txt', 'w')
    except OSError:
        print('\nFailed to open file.\n')
        return -1

    test_file2.write('1 2 3 4 5')
    test_file2.close()

    test2 = FFF("test2.txt")

    if (test2 == 2):
        return 1

    else:
        return 0

    
def Core_test():
    if (Auto_test1() * Auto_test2() == 1):
        return 1
    else:
        return 0


if (Core_test() == 1):

    name = input("Enter the of file you want to read:\n")
  
    answer = FFF(name)
    
    if(answer >= 0):
        print("\nMean square deviation from arithmetic mean is: ")
        print(FFF(name))
    print("\n")

    if(answer == -2):
        print("File is empty.\n")

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
 





