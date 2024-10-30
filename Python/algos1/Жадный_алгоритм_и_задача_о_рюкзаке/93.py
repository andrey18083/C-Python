m=int(input())
a=list(map(int, input().split()))
b=[(2**i/a[i], a[i], 2**i) for i in range(31)]
p1=0
p2=float("inf")

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
b=qwer(b)

for i in b:
    if i[1]<=m:
        k=m//i[1]
        p1+=k*i[2]
        m-=k*i[1]
    p2=min(p2, p1+i[2])
    if m==0:
        break
if p1<p2:
    print(p1)
else:
    print(p2)