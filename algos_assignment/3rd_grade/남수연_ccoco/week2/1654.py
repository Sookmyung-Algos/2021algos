import sys
input = sys.stdin.readline

def check(num):
    cnt = 0
    for i in range(k):
        cnt += lan[i] // num
    return cnt >= n


def bsearch(left, right):
    ans = 1
    while left <= right:
        mid = (left + right) // 2
        if check(mid):
            left = mid + 1
            ans = max(ans, mid)
        else:
            right = mid - 1
    return ans


k, n = map(int, input().split())
lan = []

for i in range(k):
    tmp = int(input())
    lan.append(tmp)

print(bsearch(1, max(lan)))
