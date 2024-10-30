k=int(input())
a=list(map(int, input().split()))
b=[[0] * k for _ in range(k)]

for i in range(k - 1):
    p1, p2=sorted(a), sorted(range(k), key=lambda x: a[x])
    for j in range(i+1, k):
        if b[p2[i]][p2[j]]>0:
            continue
        elif p1[i]>0:
            b[p2[i]][p2[j]]=1
            b[p2[j]][p2[i]]=1
            p1[i]-=1
            a[p2[j]]-=1
        elif p1[i]==0:
            b[p2[j]][p2[i]]=2
            a[p2[j]]-=2
    a[p2[i]]=-i-1

for i in b:
    print(*i)