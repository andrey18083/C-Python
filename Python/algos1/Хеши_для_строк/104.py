s=input()
q=int(input())

for _ in range(q):
    l, a, b = map(int, input().split())
    otv=0
    for i in range(l):
        if s[a+i]!=s[b+i]:
            otv=1 if s[a+i]>s[b+i] else -1
            break
    print(otv)