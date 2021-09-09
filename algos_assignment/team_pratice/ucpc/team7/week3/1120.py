a, b = input().split()
short = b
long = a
answer = 9999999

if len(a) < len(b):
    short = a
    long = b

for i in range(len(long) - len(short) + 1):
    count = 0
    for j in range(len(short)):
        if long[i + j] != short[j]:
            count += 1
    answer = min(answer, count)

print(answer)
