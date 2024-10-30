class Queue:
    def __init__(self):
        self.q=[]

    def push(self, n):
        self.q.append(n)
        print("ok")

    def pop(self):
        if len(self.q)==0:
            print("error")
        else:
            print(self.q.pop(0))

    def front(self):
        if len(self.q)==0:
            print("error")
        else:
            print(self.q[0])

    def size(self):
        print(len(self.q))

    def clear(self):
        self.q=[]
        print("ok")

q=Queue()

while True:
    c=input().split()
    if c[0]=="push":
        q.push(int(c[1]))
    elif c[0]=="pop":
        q.pop()
    elif c[0]=="front":
        q.front()
    elif c[0]=="size":
        q.size()
    elif c[0]=="clear":
        q.clear()
    elif c[0]=="exit":
        print("bye")
        break