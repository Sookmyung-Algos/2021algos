import sys
input = sys.stdin.readline
n = int(input())
no = int(input())
nol = list(map(int, input().split()))
v = [True]*10
for i in nol:
    v[i] = False
if n==100 or True not in v:
    print(abs(n-100))
else:
    cnt = 0
    temp = n
    while True:
        flag = 1
        if temp-cnt>=0:
            for i in str(temp-cnt):
                if v[int(i)]==False: flag = 0
            if flag == 1:
                mincnt = len(str(temp-cnt))+cnt
                break
        flag = 1
        for i in str(temp+cnt):
            if v[int(i)]==False: flag = 0
        if flag == 1:
            mincnt = len(str(temp+cnt))+cnt
            break
        cnt += 1
    mincnt = min(mincnt, abs(n-100))
    print(mincnt)
