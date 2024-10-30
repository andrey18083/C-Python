def qwer(a, b, dl):
    def zxc1(x, a):
        if x<a[0]:
            return 0
        l=0
        r=len(a)-1
        while l<r:
            m=(l+r+1)//2
            if a[m]>x:
                r=m-1
            else:
                l=m
        return l+1
    def zxc2(a1, a2):
        l=min(a1[0], a2[0])
        r=max(a1[-1], a2[-1])
        while l<r:
            m=(l+r)//2
            if zxc1(m, a1)+zxc1(m, a2)>=dl:
                r=m
            else:
                l=m+1
        return l
    return zxc2(a, b)

n,l=map(int, input().split())
otv=[]
for i in range(n):
    x1,d1,a,c,m=map(int, input().split())
    p1=[x1]
    for i in range(1, l):
        x1=x1+d1
        p1.append(x1)
        d1=(d1*a+c)%m
    otv.append(p1)
for i in range(n - 1):
    for j in range(i + 1, n):
        print(qwer(otv[i], otv[j], l))