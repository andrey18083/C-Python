i1,i2,i3,i4 = 0, 0, 0, 0
n1=int(input())
a1=list(map(int, input().split()))
n2=int(input())
a2=list(map(int, input().split()))
n3=int(input())
a3=list(map(int, input().split()))
n4=int(input())
a4=list(map(int, input().split()))
a1.sort()
a2.sort()
a3.sort()
a4.sort()
minq=min(a1[0], a2[0], a3[0], a4[0])
maxq=max(a1[0], a2[0], a3[0], a4[0])
p1=abs(maxq-minq)
min1=i1
min2=i2
min3=i3
min4=i4
while i1<n1 and i2<n2 and i3<n3 and i4<n4:
    minq=min(a1[i1], a2[i2], a3[i3], a4[i4])
    maxq=max(a1[i1], a2[i2], a3[i3], a4[i4])
    p2=abs(maxq - minq)
    if p2<p1:
        p1=p2
        min1=i1
        min2=i2
        min3=i3
        min4=i4
    if p2<1:
        break
    while i1<len(a1) and minq==a1[i1]:
        i1+=1 
    while i2<len(a2) and minq==a2[i2]:
        i2+=1
    while i3<len(a3) and minq==a3[i3]:
        i3+=1
    while i4<len(a4) and minq==a4[i4]:
        i4+=1
print(a1[min1], a2[min2], a3[min3], a4[min4])