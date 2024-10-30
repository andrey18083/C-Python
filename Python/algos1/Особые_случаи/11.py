def calculate_temperature(a,b,c):
    if c=="freeze":
        if a>b:
            return b
        else:
            return a
    elif c=="heat":
        if a<b:
            return b
        else:
            return a
    elif c=="auto":
        return b
    elif c=="fan":
        return a
a=str(input())
a,b=map(int, a.split())
c=str(input()) 

d=calculate_temperature(a,b,c)
print(d)