a=int(input())
b=int(input())
n=int(input())
m=int(input())

g1=a*(n-1)+n
g2=a*(n+1)+n
g3=b*(m-1)+m
g4=b*(m+1)+m
r1=0
r2=0
if g1>g3:
    r1=g1
else:
    r1=g3
if g2>g4:
    r2=g4
else:
    r2=g2
if r1>r2:
    print(-1)
else:
    print(r1,r2)
