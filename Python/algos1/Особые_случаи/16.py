a=str(input())
r=0
n,i,j=map(int, a.split())
if i>j:
	r=j-(i-n)-1
else:
	r=i-(j-n)-1
if i>j:
	c=i-j-1
else:
	c=j-i-1
if r>c:
	print(c)
else:
	print(r)