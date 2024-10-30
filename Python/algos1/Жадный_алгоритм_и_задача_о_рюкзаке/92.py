n, k, s = map(int, input().split())
b=[[0]*k for _ in range(k)]
c=0
for i in range(k):
    for j in range(k):
        if c==s:
            break
        b[i][j]=1
        c+=1

for _ in range(n//k):
    for i in b:
        print(*i*(n//k), sep=" ", end=" ")
        print(*i[:n%k], sep=" ")
        
for i in range(n%k):
    print(*b[i]*(n//k), sep=" ", end=" ")
    print(*b[i][:n%k], sep=" ")