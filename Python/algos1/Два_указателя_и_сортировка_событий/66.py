n,m=map(int,input().split())
a=[]
for i in range(m):
    k1,k2=map(int,input().split())
    a.append((k1,1))
    a.append((k2,2))
a=sorted(a)
otv=0
otv=otv+a[0][0]-0
otv=otv+n-1-a[len(a)-1][0]
k=0
for j in range(len(a)-1):
    if a[j][1]==1:
        k+=1
    elif a[j][1]==2:
        k-=1
    if k==0:
        p1=a[j+1][0]-a[j][0]
        if p1>0:
            otv+=p1-1
print(otv)