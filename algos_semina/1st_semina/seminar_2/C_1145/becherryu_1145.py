import sys

nums = list(map(int, sys.stdin.readline().split()))
n = min(nums) #가장 작은 수 부터 나누기

while True:
    count = 0
    for i in range(5):
        if n % nums[i] == 0:
            count += 1
    if count > 2:
        print(n)
        break
    n += 1
