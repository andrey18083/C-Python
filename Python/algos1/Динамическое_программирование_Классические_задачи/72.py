def qwer(n, k):
    a=[0]*n
    a[0]=1

    for i in range(1, n):
        for j in range(1, min(k,i)+1):
            if i>=j:
                a[i]+=a[i-j]

    return a[n-1]

n, k=map(int, input().split())
print(qwer(n,k))