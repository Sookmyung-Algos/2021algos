import sys
input= sys.stdin.readline

cnt=1
while(True):
    L, P, V= map(int, input().split())
    if(L==0 and P==0 and V==0):
        break
    if V%P>=L:
        result= V//P*L+L
    else:
        result= V//P*L+V%P
    print("Case %d: %d" %(cnt, result))
    cnt+=1
