import copy
def qwer(a):
    n=len(a)
    for i in range(1,n):
        b=copy.deepcopy(a)
        k=a[i]
        j=i-1
        while j>=0 and a[j]>k:
            a[j+1]=a[j]
            j-=1
        a[j+1]=k
        if b!=a:
            print(*a)

N=int(input())
a=list(map(int, input().split()))
print()
qwer(a)