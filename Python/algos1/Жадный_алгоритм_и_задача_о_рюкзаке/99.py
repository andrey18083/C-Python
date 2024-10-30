n=int(input())
a, b, c = map(int, input().split())
p1=[0]*(n+1)
p1[1]=1
for i in range(2, n+1):
    if i-a>=0 and p1[i-a]==1:
        p1[i]=1
    elif i-b>=0 and p1[i-b]==1:
        p1[i]=1
    elif i-c>=0 and p1[i-c]==1:
        p1[i]=1
print(sum(p1))   