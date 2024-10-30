a,b,c,d=map(int, input().split())
s=[]
r=[]
l=[]
s.append(a+c)
r.append(max(b,d))

s.append(a+d)
r.append(max(b,c))

s.append(d+b)
r.append(max(a,c))

s.append(b+c)
r.append(max(a,d))

l.append(s[0]*r[0])
l.append(s[1]*r[1])
l.append(s[2]*r[2])
l.append(s[3]*r[3])
g=min(l)
for i in range(4):
	if g==l[i]:
		print(s[i],r[i])
		break