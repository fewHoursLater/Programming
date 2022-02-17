
def Spinner(value,firstlist,secondlist):
    for A in range(0,len(firstlist)):
        for B in range(0,len(firstlist)):
            for C in range(0,len(firstlist)):
                if(A!=B and A!= C and B!=C):
                    
                    sign_of_first_ex = (firstlist[A][0] - secondlist[value][0]) * (firstlist[B][1] - firstlist[A][1]) - (firstlist[B][0] - firstlist[A][0]) * (firstlist[A][1] - secondlist[value][1])
                    sign_of_second_ex = (firstlist[B][0] - secondlist[value][0]) * (firstlist[C][1] - firstlist[B][1]) - (firstlist[C][0] - firstlist[B][0]) * (firstlist[B][1] - secondlist[value][1])
                    sign_of_third_ex = (firstlist[C][0] - secondlist[value][0]) * (firstlist[A][1] - firstlist[C][1]) - (firstlist[A][0] - firstlist[C][0]) * (firstlist[C][1] - secondlist[value][1])

                    if((sign_of_first_ex > 0 and sign_of_second_ex > 0 and sign_of_third_ex > 0) or (sign_of_first_ex < 0 and sign_of_second_ex < 0 and sign_of_third_ex < 0)):
                        return 1
    
    return 0

def points_inside_polygon(f_name):
    try:
        file = open(f_name,'r')
    except OSError:
        print('\nFailed to open file.\n')
        return -1

    cnt = 0
    
    for line in file:
        for g in line.split():
            try:
                cnt += 1
                float(g)
            except ValueError:
                print("\nWrong Value.\n")
                file.close()
                return -1
    if(cnt %2!= 0 or cnt == 0):
        print("\nNot enough values.\n")
        file.close()
        return -1;

    file.close()


    poly = []
    i = 1

    try:
        file = open(f_name,'r')
    except OSError:
        print('\nFailed to open file.\n')
        return -1

    for line in file:
        for r in line.split():
            try:
                if(i == 1):
                    x = r
                    i = i +1
                    cnt = cnt+1
                    continue
                if(i == 2):
                    y = r
                    i = 1
                    
                    poly.append((float(x),float(y)))                    
                    
            except ValueError:
                print("\nWrong value.\n")
                file.close()
                return -1
    
    file.close()
     
    MAX_X = poly[0][0]
    MIN_X = poly[0][0]
    MAX_Y = poly[0][1]
    MIN_Y= poly[0][1]

    for k in range(0,len(poly)): 
        
        if(poly[k][0] >= MAX_X):
            MAX_X = poly[k][0]

        if(poly[k][0] <= MIN_X):
            MIN_X = poly[k][0]

        if(poly[k][1] >= MAX_Y):
            MAX_Y = poly[k][1]

        if(poly[k][1] <= MIN_Y):
            MIN_Y = poly[k][1]

    MAX_IX = round(MAX_X)
    MIN_IX = round(MIN_X) 
    MAX_IY = round(MAX_Y)
    MIN_IY = round(MIN_Y)
   
    if(MAX_IX>MAX_X):
        MAX_IX = MAX_IX - 1
    if(MIN_IX<MIN_X):
        MIN_IX = MIN_IX +1
    if(MAX_IY > MAX_Y):
        MAX_IY = MAX_IY - 1
    if(MIN_IY < MIN_Y):
        MIN_IY = MIN_IY + 1

    points = []

    for L in range(MIN_IX,MAX_IX+1): 
        for H in range(MIN_IY,MAX_IY+1):
            points.append((L,H))

    if(len(poly)<3):
        print("\nThere should be at least three points.\n")
        file.close()
        return -1

    origin_length = len(points)
    
    step = 0;
    
    sign_of_first_ex = 0.
    sign_of_second_ex =0.
    sign_of_third_ex =0.
    
    
    for F in range(0,len(points)):
        F = F - step
        
        if(Spinner(F,poly ,points) == 1):
            del points[F]
            step = step + 1
        
    return(origin_length-len(points))

name = input("Enter the name of file:\n")

if(points_inside_polygon(name)>=0):
   print("\nNumber of points lying inside: ",points_inside_polygon(name),'\n')

    

    






