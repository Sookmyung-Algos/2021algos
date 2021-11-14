lst = []
flag = True
sum = 0

for i in range(46):
    for j in range(i):
        lst.append(i)
        if len(lst) >= 1000:
            flag = False
            break
    if not flag:
        break

start, end = map(int, input().split())

for k in range(start - 1, end):
    sum += lst[k]

print(sum)
