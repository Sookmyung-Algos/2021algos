def b_s(l, a):
    start, end = 0, len(l)-1
    count = -1
    while start <= end:
        mid = (start + end) // 2
        if l[mid] < a:
            count = mid
            start = mid + 1
        else:
            end = mid - 1
    return count
    
for i in range(int(input())):
    N, M = map(int, input().split())
    A = sorted(list(map(int, input().split())))
    B = sorted(list(map(int, input().split())))
    cnt = 0
    for a in A:
        cnt += (b_s(B, a) + 1)
    print(cnt)
