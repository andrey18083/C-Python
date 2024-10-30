n = int(input())

for i in range(n):
    x1,y1,x2,y2,x3,y3,x4,y4=list(map(int, input().split()))

    if (abs(x1-x2)==abs(x3-x4) and abs(y1-y2)==abs(y3-y4)) or (abs(x1-x2)==abs(x3-x4) and abs(y1-y2)==abs(y3-y4)):
        print('YES')
    elif (abs(x1-x3)==abs(x2-x4) and abs(y1-y3)==abs(y2-y4)) or (abs(x1-x3)==abs(x2-x4) and abs(y1-y3)==abs(y2-y4)):
        print('YES')
    elif (abs(x1-x4)==abs(x2-x3) and abs(y1-y4)==abs(y2-y3)) or (abs(x1-x4)==abs(x2-x3) and abs(y1-y4)== abs(y2-y3)):
        print('YES')
    else:
        print('NO')