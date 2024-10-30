n, m=map(int, input().split())
d={}

for _ in range(n):
    st=input()
    for i in st:
        d[i]=d.get(i, 0)+1

for _ in range(m):
    st=input()
    for i in st:
        d[i]=d.get(i, 0) - 1

for i, k in d.items():
    if k>0:
        print(i*k, end="")