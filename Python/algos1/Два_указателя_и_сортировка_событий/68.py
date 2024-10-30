n=int(input())
a=[0]*1440
otv=0
for i in range(n):
    p1, p2, p3, p4=map(int, input().split())
    k1=p1*60+p2
    k2=p3*60+p4
    if k1>=k2:
        for j in range(k1, 1440):
            a[j]+=1
        for j in range(k2):
            a[j]+=1
    else:
        for j in range(k1, k2):
            a[j]+=1
    otv=a.count(n)
print(otv)