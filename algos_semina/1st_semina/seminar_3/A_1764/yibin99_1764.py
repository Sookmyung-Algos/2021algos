import sys
n, m = map(int, sys.stdin.readline().split())
set1 = set()
set2 = set()
for i in range(n):
    set1.add(sys.stdin.readline().rstrip())
for j in range(m):
    name = sys.stdin.readline().rstrip()
    if name in set1:
        set2.add(name)
set2 = sorted(set2)
print(len(set2))
print('\n'.join(set2))
