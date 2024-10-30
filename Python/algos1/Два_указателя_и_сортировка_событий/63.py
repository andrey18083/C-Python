n, m=map(int, input().split())
a=list(map(int, input().split()))

k1=k2=otv=0

while k1<n:
    while k2<n and a[k2]-a[k1]<=m:
        k2+=1
    otv+=n-k2
    k1+=1

print(otv)