a=input().strip()

k=0
n=len(a)
for i in range(n):
    p1=p2=i
    while p1>=0 and p2<n and a[p1]==a[p2]:
        k+=1
        p1-=1
        p2+=1
for i in range(n-1):
    p1=i
    p2=i+1
    while p1>=0 and p2<n and a[p1]==a[p2]:
        k+=1
        p1-=1
        p2+=1
print(k)