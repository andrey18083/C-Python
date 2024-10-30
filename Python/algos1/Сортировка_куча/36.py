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

N=list(map(int, input().split()))
a1=list(map(int, input().split()))
a2=list(map(int, input().split()))
a3=list(map(int, input().split()))

print(*qwer(qwer(a1,a2),a3))