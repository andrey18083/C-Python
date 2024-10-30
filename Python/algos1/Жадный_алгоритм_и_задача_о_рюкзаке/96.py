n,m=map(int, input().split())
mi=list(map(int, input().split()))

b=[0]*(m+1)
b[0]=1

for i in mi:
    for j in range(m, i-1, -1):
        if b[j-i]==1:
            b[j]=1

for i in range(m, -1, -1):
    if b[i]==1:
        print(i)
        break