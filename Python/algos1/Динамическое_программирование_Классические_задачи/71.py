def qwer(n):
    if n==0:
        return 1

    if n==1:
    	return 2

    a=[0]*(n+1)
    a[0]=1
    a[1]=2
    a[2]=4

    for i in range(3, n+1):
        a[i]=a[i-1]+a[i-2]+a[i-3]

    return a[n]


n=int(input())
print(qwer(n))