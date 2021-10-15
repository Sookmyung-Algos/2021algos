from sys import stdin
input= stdin.readline

n= int(input())
for i in range(n):
    p= list(input())
    l=0
    maxl=0
    if(len(p)==0):
        print(1)
    else:
        for c in p:
            if(c=='['):
                l= l+1
                if(l>maxl):
                    maxl=l
            elif(c==']'):
                l= l-1
        result=1
        for j in range(maxl):
            result = result*2
        print(result)
