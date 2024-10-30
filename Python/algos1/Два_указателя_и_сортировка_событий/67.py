n, m=map(int, input().split())
P1=[]
for i in range(n):
    a,b=map(int, input().split())
    a,b=min(a, b), max(a, b)
    P1.append((a, '('))
    P1.append((b, ')'))
m=list(map(int, input().split()))
for i in range(len(m)):
    P1.append((m[i], '(('))
k=0
P1.sort()
otv = {}
for i, dj in P1:
    if dj=='(':
        k+=1
    elif dj==')':
        k-=1
    else:
        otv[i]=k
for i in m:
    print(otv[i], end=" ")