n=int(input())
st=input()
st=sorted(st)

dl={}
for i in st:
    dl[i]=dl.get(i, 0) + 1

s=[]
ch=''
ln=0
b=False

for i, k in dl.items():
    if k%2 and k>ln:
        ln=k
        b=True
        ch=i

for i, k in dl.items():
    s+=i*(k//2)

if b:
    print(*s,ch,*s[::-1], sep="")
else:
    print(*s,*s[::-1], sep="")