n=int(input())
ta=list(map(int, input().split()))[::-1]

a=set(ta)
b=[]
for i in ta:
    if i in a:
        b.append(i)
        a.remove(i)

print(len(b))
print(*b[::-1])