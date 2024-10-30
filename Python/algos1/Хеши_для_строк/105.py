a=str(input())
b=[0]*len(a)
p1, p2=0, 0
for i in range(1, len(a)):
    if i<=p2:
        b[i]=min(p2-i+1, b[i-p1])
    while i+b[i]<len(a) and a[b[i]]==a[i+b[i]]:
        b[i]+=1
    if i+b[i]-1>p2:
        p1, p2=i, i+b[i]-1
print(*b)