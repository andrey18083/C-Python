n=int(input())
a=list(map(int, input().split()))
b=0
otv=a[0]
for i in a:
	b+=i
	otv=max(otv,b)
	if b<0:
		b=0
print(otv)