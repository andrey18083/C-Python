def qwer(f, N):
    m=a[0]
    k=0
    for i in range(f,N):
    	if a[i]>m:
    		m=a[i]
    		k=i
    return k

N=int(input())
if N==0:
	raise SystemExit
a=list(map(int, input().split()))
for i in range(N):
	a[qwer(0,N-i)], a[N-i-1]=a[N-i-1], a[qwer(0,N-i)]
print(*a)