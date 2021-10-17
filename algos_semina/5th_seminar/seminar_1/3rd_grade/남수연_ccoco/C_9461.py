cache = [0] * 100
cache[0] = cache[1] = cache[2] = 1
cache[3] = cache[4] = 2

for i in range(5, 100):
    cache[i] = cache[i-5] + cache[i-1]

n = int(input())
for i in range(n):
    print(cache[int(input())-1])
