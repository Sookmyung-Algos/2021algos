#https://velog.io/@uoayop/BOJ-10025-%EA%B2%8C%EC%9C%BC%EB%A5%B8-%EB%B0%B1%EA%B3%B0Python 코드참고
#투 포인터이용
import sys
from collections import defaultdict
input = sys.stdin.readline

n, k = map(int,input().rsplit())
ice = defaultdict(int)
mn, mx, answer = sys.maxsize, 0, -1

for _ in range(n):
    g, x = map(int,input().rsplit())
    ice[x] = g
    mx = max(mx, x) #맨 오른쪽 좌표
    mn = min(mn, x) #맨 왼쪽 좌표
# start, end = 포인터
# curr 현재 얼음 양
    
end, curr = mn, 0
for start in range(mn, mx + 1):
    while end < mx + 1 and end - start <= k * 2:
        if ice[end] == 0:
            end += 1
            continue
        curr += ice[end] 
        end += 1
    answer = max(answer, curr)
    curr -= ice[start]
    
print(answer)
