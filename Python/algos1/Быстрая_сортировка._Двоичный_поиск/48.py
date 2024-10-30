a=list(map(int, input().split()))
p1=0
p2=max(a[0],a[1])*a[2]
while p1<p2:
    p3=(p1+p2)//2
    o=(p3//a[0])*(p3//a[1])
    if o<a[2]:
        p1=p3+1
    else:
        p2=p3

print((p2))