def insert(heap, k):
    heap.append(k)
    a=len(heap)-1
    while a>0 and heap[a]>heap[(a-1)//2]:
        heap[a], heap[(a-1)//2]=heap[(a-1)//2], heap[a]
        a=(a-1)//2
def extract(heap):
    a=heap[0]
    b=heap.pop()
    if len(heap)>0:
        heap[0]=b
        qwer(heap, 0)

    return a

def qwer(heap, i):
    m=i
    p1=2*i+1
    p2=2*i+2
    if p1<len(heap) and heap[p1]>heap[m]:
        m=p1
    if p2<len(heap) and heap[p2]>heap[m]:
        m=p2
    if i!=m:
        heap[i], heap[m]=heap[m], heap[i]
        qwer(heap,m)

n=int(input())
heap=[]
for i in range(n):
    c=list(map(int, input().split()))
    if c[0]==0:
        insert(heap, int(c[1]))
    elif c[0]==1:
        print(extract(heap))