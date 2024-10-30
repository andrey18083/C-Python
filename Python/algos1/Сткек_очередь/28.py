N=int(input())
o=[]
for i in range(N):
	tests=list(map(float, input().split()))
	b=0
	for j in range(1, len(tests)-2):
		if tests[j]<tests[j+1] and tests[j+2]<tests[j]<tests[j+1]:
			b=1
	if b==0:
		o.append(1)
	else:
		o.append(0)
for i in range(len(o)):
	print(o[i])