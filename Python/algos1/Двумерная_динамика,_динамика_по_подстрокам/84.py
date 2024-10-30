s=input()
n=len(s)
dp=[[0]*n for _ in range(n)]
a=[[0]*n for _ in range(n)]

for i in range(n):
    dp[i][i]=1

for i in range(n):
    for j in range(i, -1, -1):
        if j==i:
            dp[j][i]=1
        else:
            minq=float('inf')
            minq2=-1
            b1=s[j]=='(' and s[i]==')'
            b2=s[j]=='[' and s[i]==']'
            b3=s[j]=='{' and s[i]=='}'
            if b1 or b2 or b3:
                minq=dp[j+1][i-1]
            for k in range(j, i):
                if minq>dp[j][k]+dp[k+1][i]:
                    minq=dp[j][k]+dp[k+1][i]
                    minq2=k
            dp[j][i]=minq
            a[j][i]=minq2

def zxc(p1, p2):
    p3=p2-p1+1
    if dp[p1][p2]==p3:
        return
    if dp[p1][p2]==0:
        print(s[p1:p2+1], end="")
        return
    if a[p1][p2]==-1:
        print(s[p1], end="")
        zxc(p1+1, p2-1)
        print(s[p2], end="")
        return
    zxc(p1, a[p1][p2])
    zxc(a[p1][p2]+1, p2)

zxc(0, n-1)