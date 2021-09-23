import sys

n = int(input())
homeworks = [[0]*2 for _ in range (N)]
#homeworks라는 배열을 하나 만들어준다.
for i in range(n):
    deadline, score = map(int, sys.stdin.readline().split())
    homeworks[i][0]= deadline
    homeworks[i][1]= score
    #for문 안에서 homeworks[i][0]과 homeworks[i][1]에 각각 deadline과 score를 넣어준다.
homeworks.sort()
#homeworks를 정렬해준다.
do    = []
date   = homeworks[n-1][0]
answer = 0

while True:
    if date == 0:
        break
        #date가 0이면 answer=0이다.
    while homeworks and homeworks[-1][0] >= date:
        do.append(homeworks.pop()[1])
        #homeworks가 비지 않았거나 homeworks[-1][0]이 date보다 클 때 do에 homeworks.pop()[1]를 append해준다.
    date -= 1
    #그리고 나서 date에 -1을 해준다.
    if not do:
        continue
        #do가 차지 않았을 경우 continue로 계속 돌아준다.
    do.sort()
    #do를 sort해준다.
    answer += do.pop()
    #answer에 do.pop()으로 마지막 것을 더해준다.
    
print(answer)
#이 과정을 반복하면 answer에 답이 들어가게 된다.
