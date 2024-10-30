m, n=map(int, input().split())
a=[[0]*m for _ in range(n)]
a[0][0]=1
for i in range(n):
    for j in range(m):
        if i!=n-1:
            a[i+1][j]+=a[i][j]
        if i!=n-1 and j!=m-1:
            a[i+1][j+1]+=a[i][j]
        if j!=m-1:
            a[i][j+1]+=a[i][j]
print(a[n-1][m-1])