def qwer(a, K):
    k1=-1
    p1=0
    p2=len(a)-1
    while p1<=p2:
        p3=(p1+p2)//2
        if a[p3]==K:
            k1=p3
            p2=p3-1
        elif a[p3]<K:
            p1=p3+1
        else:
            p2=p3-1
    if k1==-1:
        return (0, 0)

    k2=-1
    p1=k1
    p2=len(a)-1
    while p1<=p2:
        p3=(p1+p2)//2
        if a[p3]==K:
            k2=p3
            p1=p3+1
        elif a[p3]<K:
            p1=p3+1
        else:
            p2=p3-1
    return (k1+1, k2+1)

N=int(input())
a=list(map(int, input().split()))
K=int(input())
b=list(map(int, input().split()))
for i in range(K):
    print(*qwer(a,b[i]))