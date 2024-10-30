def qwer(a1,a2):
    res=[]
    i,j=0,0

    while i<len(a1) and j<len(a2):
        if a1[i]<=a2[j]:
            res.append(a1[i])
            i+=1
        else:
            res.append(a2[j])
            j+=1

    while i<len(a1):
        res.append(a1[i])
        i+=1
    while j<len(a2):
        res.append(a2[j])
        j+=1

    return res

def zxc(a1):
    if len(a1)<=1:
        return a1

    cen=len(a1)//2
    lev=a1[:cen]
    prav=a1[cen:]
    lev=zxc(lev)
    prav=zxc(prav)
    return qwer(lev, prav)

N=int(input())
a1=list(map(int, input().split()))

print(*zxc(a1))