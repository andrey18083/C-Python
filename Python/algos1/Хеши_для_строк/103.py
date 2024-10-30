a=input()  
b=[ord(i) for i in a]  
p1=27  
p2=[0] 
p3=[1]
l=10**9+9
for i in range(len(b)):
    p2.append((p2[-1]*p1+b[i])%l)
    p3.append((p3[-1]*p1)%l)

def check(p2, p3, a, b, k):
    l=10**9+9
    per1=(p2[a+k-1]-p2[a-1]*p3[k]) % l
    per2=(p2[b+k-1]-p2[b-1]*p3[k]) % l
    return 1 if per1 == per2 else 0

for k in range(1, len(a) + 1):
    o=True 
    for i in range(1, len(a)+2-k,k):
        if check(p2, p3, 1, i, k)==0:
            o=False
            break
    if check(p2, p3, 1, k*(len(a)//k)+1, len(a)%k)==0:
        o=False
    if o:
        print(k)
        raise SystemExit