from sys import stdin
cnt = 0
dct = {}
while True:
    n = sys.stdin.readline()
    if n == "":
        break
    elif n in dct:
        dct[n] += 1
    else: 
        dct[n] = 1
    cnt += 1

for i, j in sorted(dct.items()):
    print("%s %.4f" %(i, j/cnt*100))

