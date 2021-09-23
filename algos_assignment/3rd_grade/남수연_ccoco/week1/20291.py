import sys
from collections import OrderedDict

r = sys.stdin.readline

n = int(r())
ext = {}

for _ in range(n):
    f, e = r().strip().split('.')
    if ext.get(e):
        ext[e] += 1
    else:
        ext[e] = 1

ordered_ext = OrderedDict(sorted(ext.items(), key=lambda x: x[0]))

for k, v in ordered_ext.items():
    print(k, v)
