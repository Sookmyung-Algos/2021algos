import sys
input=sys.stdin.readline
left,right=map(str,input().split())
cnt=0
if len(left)!=len(right):
    print(0)
else:
    for i in range(len(left)):
        if left[i]==right[i]:
            if left[i]=='8':
                 cnt+=1
        else:
            break
    print(cnt)
