def qwer(a):
	n=len(a)
	k=0
	for j in range(n):
		for i in range(1,n):
			if a[i-1]>a[i]:
				a[i], a[i-1]=a[i-1], a[i]
				k+=1
	return k

N=int(input())
a=list(map(int, input().split()))

print(qwer(a))