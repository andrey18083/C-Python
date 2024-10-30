def swap_max_with_last(a, f, N):
    m=f
    k=f

    while k!=N:
        if a[k]>a[m]:
            m=k
        k+=1
    
    a[m],a[N-1]=a[N-1],a[m]

N=int(input())
a=list(map(int, input().split()))
f=0

swap_max_with_last(a, f, N)
print(*a)