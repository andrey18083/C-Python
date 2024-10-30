a=str(input())
x,y,z=map(int,a.split())
if x==y:
	print(1)
elif y<=12 and x<=12:
	print(0)
else:
	print(1)