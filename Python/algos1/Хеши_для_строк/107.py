n=int(input())
a=str(input())
a=a+a[::-1]
n=len(a)
b=[0]*n
p1=10**9
c, c1=0, 0
for i in range(n):
    if p1>=0:
        d=0
    if i<=c1:
        d=b[i-c]
        if i+d-1<c1:
            b[i]=d
            p1=0
            continue
        else:
            d=c1-i+1
    while i+d<n and a[d]==a[i+d]:
        d+=1
    b[i]=d
    c, c1=i, i+d-1

for i in range(n-1, n//2-1, -1):
    print(b[i], end=" ")