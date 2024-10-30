n=int(input())
d={}
p1=0
for i in range(1, n+1):
    p2=int(input())
    if p2==0:
        p3=input()
        d[i]=[0, p3, 0]
        p3=input()
    else:
        p3=input()
        d[i]=[0,p3,p2]
        p4=p2
        while d[p4][2]!=0:
            p4=d[p4][2]
        d[p4][0]+=1
        p1=max(p1,d[p4][0])
for i in d:
    if d[i][0]==p1:
        print(d[i][1])
        raise SystemExit