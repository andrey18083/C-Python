n=int(input())
c=list(map(int, input().split()))
k=int(input())
p=list(map(int, input().split()))
p1=[0]*k
for i in range(len(p)):
    p1[p[i]-1]+=1
for i in range(len(c)):
    if p1[i]>c[i]:
        print('yes')
    else:
        print('no')