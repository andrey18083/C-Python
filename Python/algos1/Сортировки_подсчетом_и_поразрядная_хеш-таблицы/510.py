X=input()
Y=input()
dl={}
dll={}

for i in range(len(X)):
    if X[i] in dl:
        dl[X[i]].append(i)
    else:
        dl[X[i]]=[i]
for i in range(len(Y)):
    if Y[i] in dll:
        dll[Y[i]].append(i)
    else:
        dll[Y[i]]=[i]

p1=-1
p2=-1
sp=[]

for i in range(123, 95, -1):
    p3=chr(i)
    if p3 not in dl or p3 not in dll:
        continue
    o1=dl[p3]
    o2=dll[p3]
    k1=next((j for j in range(len(o1)) if o1[j]>p1), -1)
    k2=next((j for j in range(len(o2)) if o2[j]>p2), -1)
    if k1!=-1 and k2!=-1:
        c=min(len(o1)-k1,len(o2)-k2)
        p1=o1[k1+c-1]
        p2=o2[k2+c-1]
        sp.extend([p3]*c)

otv=''.join(sp)
print(otv)