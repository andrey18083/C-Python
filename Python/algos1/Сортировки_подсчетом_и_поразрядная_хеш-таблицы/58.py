g, qqq = map(int, input().split())    
W=input()
S=input()
dl={}
for i in W:
    dl[i]=dl.get(i, 0) + 1
otv=0
dll={}
    
for i in S[:g]:
    dll[i]=dll.get(i, 0)+1
    
for i in range(g, len(S)):
    if dll==dl:
        otv+=1  
    p2=S[i-g]
    dll[p2]-=1
    if dll[p2]==0:
        del dll[p2]   
    p3=S[i]
    dll[p3]=dll.get(p3, 0)+1

if dll==dl:
    otv+=1

print(otv)
