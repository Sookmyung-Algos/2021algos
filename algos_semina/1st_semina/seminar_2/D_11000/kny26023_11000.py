import sys
import heapq
si = sys.stdin.readline
#input은 느리기 때문에 sys.stdin.readline으로 받아준다.
 
cnt, n= 1, int(si())
tt, rooms = [], []

for _ in range(n):
    [a, b] = [int(e) for e in si().split()]
    heapq.heappush(tt, (a, b))
    #tt라는 배열에 a, b를 넣어준다. 
 
heapq.heappush(rooms, heapq.heappop(tt)[1])
#heapq.heappop(tt)[1]를 rooms에 넣어준다.
    
while tt:
    curr = heapq.heappop(tt)
    if curr[0] < rooms[0]:
        cnt += 1
    else:
        heapq.heappop(rooms)
    heapq.heappush(rooms, curr[1])
    #curr는 heapq.heappop(tt)로 tt에서 위에 것을 뽑아서 비교하게 된다.
    #이때 curr[0]<rooms[0]일 경우 cnt, 즉 필요한 방의 개수를 1개 더해준다.
    #아닐 경우 heappop(rooms)를 해준다.
    
print(cnt)
