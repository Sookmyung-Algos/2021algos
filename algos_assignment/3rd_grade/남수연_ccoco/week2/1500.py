s, k = map(int, input().split())

lst = [s // k] * k

if s / k != s // k:
    count = s % k
    for i in range(len(lst)):
        if count != 0:
            lst[i] += 1
            count -= 1

mul = 1
for i in lst:
    mul *= i

print(mul)
