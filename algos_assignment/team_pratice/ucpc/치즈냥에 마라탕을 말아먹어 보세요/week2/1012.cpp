import sys

n = int(sys.stdin.readline())
arr = [0] * n
edges = []

for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().rstrip().split(" "))
    arr[a - 1] += 1
    arr[b - 1] += 1
    edges.append([a, b])
resD, resG = 0, 0

for i in range(n):
    if arr[i] >= 3:
        resG += arr[i] * (arr[i] - 1) * (arr[i] - 2) / 6
    else:
        resG += 0

for a, b in edges:
    resD += (arr[a - 1] - 1) * (arr[b - 1] - 1)

if resD > resG * 3:
    print("D")
elif resD < resG * 3:
    print("G")
else:
    print("DUDUDUNGA")
