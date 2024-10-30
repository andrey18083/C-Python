l, n=map(int, input().split())
a=[0]+list(map(int, input().split()))+[l]
n+=2

b=[[0]*n for _ in range(n)]

for j in range(1, n):
    for i in range(j-2, -1, -1):
        b[i][j]=float('inf')
        for k in range(i+1, j):
            b[i][j]=min(b[i][j], b[i][k]+b[k][j])
        b[i][j]+=a[j]-a[i]

print(b[0][n-1])