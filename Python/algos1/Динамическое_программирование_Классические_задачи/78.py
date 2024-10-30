n=int(input())
a=list(map(int, input().split()))
b=[1]*n
for i in range(1, n):
    for j in range(i):
        if a[i]>a[j]:
            b[i]=max(b[i], b[j]+1)

k=max(b)

otv=[]
l=k
for i in range(n-1,-1,-1):
    if b[i]==l:
        otv.append(a[i])
        l-=1

print(*list(reversed(otv)))