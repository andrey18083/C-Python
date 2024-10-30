n,m=map(int, input().split())
s=input()

p1={}
p2={}
k1=k2=l=0

for i in s:
    p1[i]=0
    p2[i]=m

for i in range(len(s)):
    p1[s[i]]+=1
    b=1
    q=0
    for j in p1:
        q+=p1[j]
        if p1[j]>p2[j]:
            b=0
            break
    if b:
        if q>k2:
            k2=q
            k1=i+1-k2
    else:
        while l<=i:
            p1[s[l]]-=1
            l+=1
            b=1
            q=0
            for j in p1:
                q+=p1[j]
                if p1[j]>p2[j]:
                    b=0
                    break
            if b:
                if q>k2:
                    k2=q
                    k1=i+1-k2
                break

print(k2, k1+1)