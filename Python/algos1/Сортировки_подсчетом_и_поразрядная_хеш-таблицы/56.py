n=int(input())
dl={}

print("Initial array:")
for i in range(10):
    dl[str(i)]=[]

p1=0

for i in range(n):
    a=input()
    p1=max(p1, len(a))
    if i==n-1:
        print(a)
    else:
        print(a, end=", ")
    
    dl[a[-1]].append(a)

print("**********")

for i in range(p1):
    dll={str(j): [] for j in range(10)}
    print("Phase", i+1)

    for j in dl:
        for h in dl[j]:
            dll[str(h[-i-1])].append(h)

    dl=dll

    for j in range(10):
        j=str(j)
        print("Bucket ", j, ": ", end="", sep="")
        
        if len(dl[j])==0:
            print('empty')
        else:
            print(*dl[j], sep=', ')

    print("**********")

print('Sorted array:')
otv=', '.join([j for i in dl.values() for j in i])
print(otv)