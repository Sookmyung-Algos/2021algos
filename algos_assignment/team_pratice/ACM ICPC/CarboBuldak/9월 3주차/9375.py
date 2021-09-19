import sys
input = sys.stdin.readline

K = int(input())
for i in range(K):
    N = int(input())
    dic = {}
    for j in range(N):
        name, t = input().split()
        if t in dic:
            dic[t] += 1
        else:
            dic[t] = 1
    s = 1
    for k, v in dic.items():
        s *= v + 1
    print(s - 1)
