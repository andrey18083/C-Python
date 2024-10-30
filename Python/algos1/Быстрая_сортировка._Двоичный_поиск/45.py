def zxc(a, N, i):
    p1=i
    p2=2*i+1
    p3=2*i+2

    if p2<N and a[p2]>a[p1]:
        p1=p2

    if p3<N and a[p3]>a[p1]:
        p1=p3

    if p1!=i:
        a[i], a[p1]=a[p1], a[i]
        zxc(a,N,p1)

def qwer(a):
    N=len(a)
    for i in range(N,-1,-1):
        zxc(a,N,i)

    for i in range(N-1,0,-1):
        a[0], a[i]=a[i], a[0]
        zxc(a,i,0)

N=int(input())
a=list(map(int, input().split()))
qwer(a)
print(*a)