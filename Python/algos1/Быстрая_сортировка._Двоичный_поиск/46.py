N, K=map(int, input().split())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
c=[]
for i in b:
    k=0
    lev=0
    prav=len(a)-1
    while lev<=prav:
        if i<a[(lev+prav)//2]:
            prav=(lev+prav)//2-1
        elif i>a[(lev+prav)//2]:
            lev=(lev+prav)//2+1
        else:
            k=1
            break
    if k==1:
        c.append(1)
    else:
        c.append(0)

for i in c:
    if i==1:
        print('YES')
    else:
        print('NO')