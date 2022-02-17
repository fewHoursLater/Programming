def FFF(filename):
    try:
        file = open(filename,'r')
    except OSError:
        print('\nFailed to open file.\n')
        return -1

     
    enter = 1
    first = 0
    second = 0
    third = 'w'
        
    flag = 0
    i = 2
    
    end = -1
    begin = -1
    s=-1
    q=0
    h=0

    for line in file:
        for x in line.split():
            try:


                if(enter == 1):
                    first = int(x)
                    enter = 2

                    continue
                if(enter == 2):
                    second = int(x)
                    enter = 3
                    continue

                if(enter == 3):
                    third = int(x)
                    enter = 0
                    
                    continue

                h=1

                   

               
                

                if (first<second and q==0):
                    begin=1
                    flag=1
                    
                q=1
                
                if (second<=first and second<third and flag==0 and q==1):
                    begin= int(i)
                    flag=1


                    
                first = int(second)
                
                second = int(third)
                
                third = int (x)

               
              
        
                
                if(second < first and second <= third and flag==1):
                    end = int(i)
                    flag = 0
                   


                if(end > begin ):
                    if((end-begin)>s):
                        s = int(end-begin)
                    
              
    
                i = int(i) + 1

                

            except ValueError:
                
                return 'uncorrecr value'

   
    if (third=='w'):
        return 'less than 3 elements'
    if (h==0):
      
        if (second>first and second>third):
            return 1
        else:
            return 0
    elif (h==1):
        first = int(second)
        second = int(third)

        if (second < first and (i- begin)>s and begin!=-1 and begin  != i-1):
            s= i- begin
        return s
       
    
        
    
    file.close()
    if (third=='w'):
        return 'less than 3 elements'



    
def Auto_test1():

    test1 = -1
    try:
        test_file1 = open('test1.txt', 'w')
    except OSError:
        print('\nFailed to open file.\n')
        return -1

    test_file1.write('0 1 1 0 1 1 1 0 1 0')
    test_file1.close()

    test1 = FFF("test1.txt")

    if (test1 == 3):
        return 1

    else:
        return 0



def Auto_test2():

    test2 = -1
    try:
        test_file2 = open('test2.txt', 'w')
    except OSError:
        print('\nFailed to open file.\n')
        return -1

    test_file2.write('1 2 3 4 5 1 2 3 4 5 6 7 1')
    test_file2.close()

    test2 = FFF("test2.txt")

    if (test2 == 6):
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

    if(answer == -11):
        print("\nFile is empty.\n")

    if(answer == -12):
        print("\nNot enough numbers in file.\n")

    if(answer == -13):
        print("\nNot enough numbers in file.\n")

    if(answer > 0):
        print("\nMaximum distance between local minimum: ")
        print(answer)
        print("\n")

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
 





