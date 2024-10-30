n, m=map(int, input().split())
x=list(map(int, input().split()))
y=list(map(int, input().split()))

srx=sorted(enumerate(x), key=lambda x: x[1])
sry=sorted(enumerate(y), key=lambda y: y[1])
otv=[0]*n
k=0
p1=0

for i, j in srx:
    while p1<m and sry[p1][1]<=j:
        p1+=1  
    if p1==m:
        break        
    otv[i]=sry[p1][0]+1
    k+=1
    p1+=1

print(k)
print(*otv)