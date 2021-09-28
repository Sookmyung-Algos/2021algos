import sys

n = int(sys.stdin.readline())
array = []

for i in range(n):
    num = list(map(int, sys.stdin.readline().split()))
    array.append(num)

array.sort(key = lambda x: (x[0], x[1]))

for i in array:
    print(i[0], i[1])

