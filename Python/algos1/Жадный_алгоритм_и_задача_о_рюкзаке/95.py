n=int(input())
a=[]

for i in range(n):
    p1,p2=map(int, input().split())
    a.append((p1, p2, i+1))
p1=int(input())
a.sort(key=lambda x: x[0]+x[1], reverse=True)
otv=[]
for i in a:
    if p1<=i[0]+i[1]:
        otv.append(i[2])
        p1=i[0]
    
print(len(otv))
print(*otv)