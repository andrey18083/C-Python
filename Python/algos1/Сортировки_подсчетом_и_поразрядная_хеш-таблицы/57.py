A=input()
B=input()
p1=[0]*10
p2=[0]*10
for i in A:
    p1[int(i)] += 1
for i in B:
    p2[int(i)] += 1

prov=False
for i in range(9, -1, -1):
    if p1[i]>0 and p2[i] > 0:
        prov=True
        if i==0:
            b=False
        break

if not prov:
    print(-1)
    raise SystemExit
b=True if i!=0 else False
if not b:
    print(0)
    raise SystemExit

otv=[]
for i in range(9, 0, -1):
    otv.extend([str(i)]*min(p1[i], p2[i]))
if b:
    otv.extend([str(0)]*min(p1[0], p2[0]))

print("".join(otv))