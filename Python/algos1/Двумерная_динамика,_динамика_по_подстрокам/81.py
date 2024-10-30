a=[-1]*256
k=[[0]*6 for _ in range(6)]
b=['N','S','W','E','U','D']

for i, j in enumerate(b):
    a[ord(j)] = i
for i in range(6):
    strr=input()
    for j in strr:
        k[i][a[ord(j)]]+=1

otv1, otv2=input().split()
otv2=int(otv2)
p1=[[1]*6 for _ in range(otv2+1)]

for i in range(2, otv2+1):
    for j in range(6):
        for q in range(6):
            p2=p1[i-1][q]*k[j][q]
            p1[i][j]+=p2

print(p1[otv2][a[ord(otv1)]])