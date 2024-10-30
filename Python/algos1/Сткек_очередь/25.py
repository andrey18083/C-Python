a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
k=0

for i in range(10**6+1):
	if i>10**6:
		print('botva')
		break
	k+=1
	q=a.pop(0)
	p=b.pop(0)
	if q>p:
		if q==9 and p==0:
			b=b+[q,p]
		else:
			a=a+[q,p]
	else:
		if q==0 and p==9:
			a=a+[q,p]
		else:
			b=b+[q,p]
	if not a:
		print('second', k)
		break
	if not b:
		print('first', k)
		break