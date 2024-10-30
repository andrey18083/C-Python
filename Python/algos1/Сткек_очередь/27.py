import collections
n,k=map(int, input().split())
a=list(map(int, input().split()))

qwe=[]
per=collections.deque()

for i in range(k):
    while per and a[i]<a[per[-1]]:
         per.pop()
    per.append(i)

for i in range(k,len(a)):
    qwe.append(a[per[0]])
    while per and per[0]<=i-k:
        per.popleft()
    while per and a[i]<a[per[-1]]:
        per.pop()

    per.append(i)

qwe.append(a[per[0]])

for minimum in qwe:
    print(minimum)