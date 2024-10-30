class Interval:
    def __init__(self, perv, kon, ps):
        self.perv=perv
        self.kon=kon
        self.ps=ps


n=int(input())
inter=[]
for i in range(n):
    inter.append(Interval(*list(map(float, input().split()))))
inter.sort(key=lambda x: x.kon)
b=[0]*n

for i in range(n):
    b[i]=inter[i].ps

    for j in range(i):
        if inter[i].perv>=inter[j].kon:
            b[i]=max(b[i], b[j]+inter[i].ps)

k=max(b)

otv=[]
p1=k
for i in range(n-1,-1,-1):
    if b[i]==p1:
        otv.append(inter[i])
        p1-=inter[i].ps

otv.reverse()

print(sum(i.ps for i in otv))