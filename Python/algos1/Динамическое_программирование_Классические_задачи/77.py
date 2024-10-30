n=int(input())
sp1=list(map(int, input().split()))
m=int(input())
sp2=list(map(int, input().split()))
a=[[0]*(m+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        if sp1[i-1]==sp2[j-1]:
            a[i][j]=a[i-1][j-1]+1
        else:
            a[i][j]=max(a[i-1][j], a[i][j-1])

otv=[]
i=n
j=m
while i>0 and j>0:
    if sp1[i-1]==sp2[j-1]:
        otv.append(sp1[i-1])
        i-=1
        j-=1
    elif a[i-1][j]>a[i][j-1]:
        i-=1
    else:
        j-=1
print(*list(reversed(otv)))