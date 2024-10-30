n, m=map(int, input().split())
a=list(map(int, input().split()))
b=list(map(int, input().split()))

c=[[0]*(m+1) for _ in range(n+1)]
    
for i in range(1, n+1):
	for j in range(1, m+1):
		if a[i-1]<=j:
			c[i][j]=max(c[i-1][j], c[i-1][j-a[i-1]]+b[i-1])
		else:
			c[i][j]=c[i-1][j]
p1=[]
p2=m
for i in range(n, 0, -1):
    if c[i][p2]!=c[i-1][p2]:
        p1.append(i)
        p2-=a[i-1]
p1.reverse()
    
for i in p1:
    print(i)