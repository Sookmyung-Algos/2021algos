from sys import stdin
input= stdin.readline

n = int(input())

for i in range(n):
    temp = int(input())
    ctype = {}
    for _ in range(temp):
        name, type = input().split()
        if(type in ctype):
            ctype[type] += 1
        else:
            ctype[type] = 1
    case = 1
    for key in ctype.keys():
        case = case * (ctype[key] + 1)
    print(case - 1)
