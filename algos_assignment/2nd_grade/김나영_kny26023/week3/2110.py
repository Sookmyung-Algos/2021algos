import sys
N, C = map(int, (input().split()))
house = [int(sys.stdin.readline()) for _ in range(N)]
#house라는 배열로 입력을 받아준다.

def router(distance):
    #해당 거리를 유지하며 공유기가 몇 개 설치될 수 있는지를 세는 함수를 하나 만든다.
    count = 1
    pos = house[0]
    #count는 1로, pos는 house[0]으로 넣어준다.
    for i in range(1, N):
        if pos + distance <= house[i]: 
          #pos에서 해당 거리보다 멀리 떨어진 house[i]이라면
            count += 1
            pos = house[i] 
            #count에 하나를 더해주고 pos를 house[i]로 갱신해준다.
    return count

house.sort()
#정렬을 해준다.
start, end = 1, house[N-1] - house[0]
#start에는 1을, end에는 마지막 집과 첫 집의 차이를 넣어준다.

while start <= end:
    mid = (start+end) // 2
    if router(mid) >= C:
        answer = mid
        start = mid + 1
    else:
        end = mid - 1
        #이분탐색 알고리즘을 적용해준다.
        
print(answer)
#그러면 answer에 답이 들어가게 된다.
