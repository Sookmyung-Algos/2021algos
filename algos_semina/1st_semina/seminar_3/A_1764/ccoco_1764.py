import sys

n, m = map(int, input().split())
cant = [sys.stdin.readline().rstrip('\n') for i in range(n+m)]
cant.sort()

count = 0
cantHearSee = []

for i in range(n+m-1):
    if cant[i] == cant[i+1]:
        count += 1
        cantHearSee.append(cant[i])

print(count)
for x in cantHearSee:
    print(x)
