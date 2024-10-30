def calculate_equation(a,b,c):
	if c<0:
		return 'NO SOLUTION'
	if a==0:
		if b!=c**2:
			return 'NO SOLUTION'
		else:
			return 'MANY SOLUTIONS'
	else:
		if (c**2-b)%a!=0:
			return 'NO SOLUTION'
		else:
			return (c**2-b)//a
a=int(input())
b=int(input())
c=int(input())
print(calculate_equation(a,b,c))