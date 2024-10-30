k=int(input())
s=input()

p1=p2=0
otv=[0]*len(s)

for i in range(len(s)-k-1,-1,-1):
    if s[i]==s[i+k]:
        p1+=1
    else:
        p1=0
    p2+=p1
    otv[i]=p2

print(otv[0])