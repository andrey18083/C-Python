n, m=map(int, input().split())
p1=list(map(int, input().split()))
p2=list(map(int, input().split()))

b=[0]*(m+1)
b[0]=0

for i in range(n):
    for j in range(m, p1[i]-1, -1):
        if b[j-p1[i]]!=-1 and b[j-p1[i]]+p2[i]>b[j]:
            b[j]=b[j-p1[i]]+p2[i]

print(max(b))