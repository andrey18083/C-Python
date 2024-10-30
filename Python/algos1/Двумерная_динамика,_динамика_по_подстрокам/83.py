def zxc(poda, k):
    l=0
    p=len(poda)-1
    q=0
    while l<p:
        if poda[l]!=poda[p]:
            q+=1
        l+=1
        p-=1
        if q>k:
            return False
    return True

def qwer(a, k):
    otv=0
    for i in range(1, len(a)+1):
        for j in range(len(a)-i+1):
            poda=a[j:j+i]
            if zxc(poda, k):
                otv+=1
    return otv

n, k=map(int, input().split())
a=str(input())

print(qwer(a,k))