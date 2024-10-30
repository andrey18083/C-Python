n, m=map(int, input().split())
a=[list(map(int, input().split())) for _ in range(n)]
b=[[0] * m for _ in range(n)]

if n==1 and m==1:
    print(a[0][0])
    print(1)
    print(1, 1)
    raise SystemExit
b[0][0]=a[0][0]
for i in range(1, m):
    b[0][i]=b[0][i-1]+a[0][i]
for i in range(1, n):
    b[i][0]=b[i-1][0]+a[i][0]

for i in range(1, n):
    for j in range(1, m):
        b[i][j]=min(b[i-1][j], b[i][j-1])+a[i][j]

print(b[n-1][m-1])

otv=[[n,m]]
n-=1
m-=1

while n!=0 or m!=0:
    if n==0:
        otv.append([n+1, m])
        m-=1
    elif m==0:
        otv.append([n, m+1])
        n-=1
    elif b[n-1][m]>b[n][m-1]:
        otv.append([n+1,m])
        m-=1
    else:
        otv.append([n, m+1])
        n-=1

print(len(otv))

for i in range(len(otv)-1,-1,-1):
    print(*otv[i])