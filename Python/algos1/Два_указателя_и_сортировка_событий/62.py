n=int(input())
a=[0, 0]
b=[0, 0]
p1, p2=-1, -1

for _ in range(n):
    x, y=map(int, input().split())
    if p1==-1:
        p1=x
        p2=y
    elif y>p2:
        a.append(a[-1]+y-p2)
        b.append(b[-1])
        p1=x
        p2=y
    else:
        a.append(a[-1])
        b.append(b[-1]+p2-y)
        p1=x
        p2=y

m=int(input())

for _ in range(m):
    x, y=map(int, input().split())
    if x>=y:
        print(b[x]-b[y])
    else:
        print(a[y]-a[x])