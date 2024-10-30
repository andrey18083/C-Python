n=int(input())
a=list(map(int, input().split()))
def qwer(a):
    if len(a)<=1:
        return a
    else:
        lev=[]
        prav=[]
        mid=[]
        centr=a[len(a)//2]
        for i in range(len(a)):
            if a[i]<centr:
                lev.append(a[i])
            elif a[i]>centr:
                prav.append(a[i])
            else:
                mid.append(a[i])
    return qwer(lev)+mid+qwer(prav)
print(*qwer(a))