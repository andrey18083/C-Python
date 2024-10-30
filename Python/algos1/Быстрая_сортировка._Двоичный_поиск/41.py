N=int(input())
a=list(map(int, input().split()))
x=int(input())
k1=0
k2=0
for i in a:
	if x>i:
		k1+=1
	else:
		k2+=1
print(k1)
print(k2)