def qwer(open, close):
    if (open=="(") and (close==")"):
       return True
    elif (open=="[") and (close=="]"):
        return True
    elif (open=="{") and (close=="}"):
       return True
    else:
        return False

def zxc(stroka):
    stack=[]
    for i in stroka:
        if i in "([{":
            stack.append(i)
        elif i in ")]}":
            if len(stack)==0 or not qwer(stack.pop(), i):
                return 'no'
    if len(stack)==0:
        return 'yes'
    else:
    	return 'no'
a=str(input())

print(zxc(a))