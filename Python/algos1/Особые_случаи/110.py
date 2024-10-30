a=str(input())
a1,a2,a3=map(int,a.split())
a=str(input())
a4,a5,a6=map(int,a.split())
a=str(input())
a7,a8,a9=map(int,a.split())
x=[]
o=[]
if a1!=0:
	if a1==1:
		x.append(a1)
	else:
		o.append(a1)
if a2!=0:
	if a2==1:
		x.append(a2)
	else:
		o.append(a2)

if a3!=0:
	if a3==1:
		x.append(a3)
	else:
		o.append(a3)

if a4!=0:
	if a4==1:
		x.append(a4)
	else:
		o.append(a4)

if a5!=0:
	if a5==1:
		x.append(a5)
	else:
		o.append(a5)

if a6!=0:
	if a6==1:
		x.append(a6)
	else:
		o.append(a6)

if a7!=0:
	if a7==1:
		x.append(a7)
	else:
		o.append(a7)

if a8!=0:
	if a8==1:
		x.append(a8)
	else:
		o.append(a8)

if a9!=0:
	if a9==1:
		x.append(a9)
	else:
		o.append(a9)
if a1==a2==a3==a4==a5==a6==a7==a8==a9==0:
	print('YES')
else:
	if a1==a2==a3==1 or a4==a5==a6==1 or a7==a8==a9==1 or a1==a5==a9==1 or a7==a5==a3==1 or a1==a4==a7==1 or a2==a5==a8==1 or a3==a6==a9==1:
		if (len(x)-len(o))!=1:
			print('NO')
		else:
			print('YES')

	elif a1==a2==a3==2 or a4==a5==a6==2 or a7==a8==a9==2 or a2==a5==a9==2 or a7==a5==a3==2 or a2==a4==a7==2 or a2==a5==a8==2 or a3==a6==a9==2:
		if (len(x)-len(o))!=0:
			print('NO')
		else:
			print('YES')

	else:
		if len(x)-len(o)==1:
			print('YES')
		else:
			print('NO')