import itertools

def zxc1(city1, city2):
    x1, y1=city1
    x2, y2=city2
    return abs(x1-x2)+abs(y1-y2)

N=int(input())
X=[]
for i in range(N):
    x,y=map(int, input().split())
    X.append((x,y))

p1=float('inf')
otv=None
for i in itertools.product(range(-100, 101), repeat=2):
    p2=0
    for j in X:
        p3=zxc1(i, j)
        p2+=p3
    p4=p2/len(X)
    if p4<p1:
        p1=p4
        otv=i

print(*otv)