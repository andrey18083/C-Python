n,m=map(int, input().split())
a=[[0]*m for _ in range(n)]
a[0][0] = 1
    
for i in range(n):
    for j in range(m):
        if i+2<n and j+1<m: 
            a[i+2][j+1]+=a[i][j]
        if i+1<n and j+2<m:
            a[i+1][j+2]+=a[i][j]
    
print(a[n-1][m-1])