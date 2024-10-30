def qwer(i, j, n, m, a):
    if not (0<=i<n and 0<=j<m):
        return 0
    if a[i][j]!=-1:
        return a[i][j]
    t=qwer(i-2,j-1,n,m,a)+qwer(i-2,j+1,n,m,a)
    a[i][j]=t+qwer(i-1,j-2,n,m,a)+qwer(i+1,j-2,n,m,a)
    return a[i][j]

n, m=map(int, input().split())
a=[[-1]*m for _ in range(n)]
a[0][0]=1
print(qwer(n-1,m-1,n,m,a))