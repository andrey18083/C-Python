n=int(input())

if n==1:
    print(0)
    print(1)
else:
    a=[10000000] * (n+1)
    a[1]=0

    for i in range(2, n+1):
        a[i]=min(a[i], a[i-1]+1)
        if i%2==0:
            a[i]=min(a[i], a[i//2]+1)
        if i%3==0:
            a[i]=min(a[i], a[i//3]+1)
    otv=[]
    k=n
    while k!=1:
        otv.append(k)
        if a[k-1]==a[k]-1:
            k-=1
        elif k%2==0 and a[k//2]==a[k]-1:
            k//=2
        elif k%3==0 and a[k//3]==a[k]-1:
            k//=3
    otv.append(1)
    print(a[n])
    print(*list(reversed(otv)))