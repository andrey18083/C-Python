with open('input.txt') as f:
    re=f.read()
    dl={}
    p1=1
    for i in re:
        if i==' ' or i=='\n':
            continue
        elif i in dl:
            dl[i]+=1
            p1=max(p1, dl[i])
        else:
            dl[i]=1
    otv=''
    for i in dl:
        otv+=i
    otv=sorted(otv)

    for i in range(p1):
        p2=''
        for i in otv:
            if dl[i]>=p1:
                p2 += '#'
            else:
                p2+=' '
        print(p2)
        p1-=1

    print(*otv, sep="")