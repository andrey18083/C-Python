import collections

d=collections.deque()

while True:
    c=input().split()
    if c[0]=="push_back":
        d.append(c[1])
        print("ok")

    elif c[0]=="push_front":
        d.insert(0, c[1])
        print("ok")

    elif c[0]=="pop_back":
        if len(d)==0:
            print('error')
        else:
            print(d.pop())

    elif c[0]=="pop_front":
        if len(d)==0:
            print('error')
        else:
            print(d.popleft())

    elif c[0]=="back":
        if len(d)==0:
            print('error')
        else:
            print(d[-1])

    elif c[0]=="front":
        if len(d)==0:
            print('error')
        else:
            print(d[0])

    elif c[0]=="size":
        print(len(d))  

    elif c[0]=="clear":
        d=collections.deque()
        print("ok")
    
    elif c[0]=="exit":
        print('bye')
        break