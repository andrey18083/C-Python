import sys
sys.set_int_max_str_digits(0)

def zxc(chi, tbl):
    if chi in tbl:
        return True

    return False

def qwer(spi):
    tbl={}
    tbl[0]=1
    tbl[1]=1

    p1=max(spi)

    a, b=0, 1
    while b<=p1:
        tbl[b]=1
        a,b=b, a+b

    otv=[]
    for chi in spi:
        if zxc(chi, tbl):
            otv.append('Yes')
        else:
            otv.append('No')

    return otv

n=int(input())
a=[]
for i in range(n):
	a.append(int(input()))
d=qwer(a)
for i in d:
	print(i)