import sys 
N = int(sys.stdin.readline()) 
#속도를 빠르게 해주기 위함이다.
time = [[0]*2 for _ in range(N)] 
#time이라는 배열을 하나 만들어준다.
for i in range(N): 
	start, end = map(int, sys.stdin.readline().split()) 
	time[i][0] = start 
	time[i][1] = end
  #for문을 돌면서 start와 end를 넣어준다.

time.sort(key = lambda x: (x[1], x[0])) 
#sort를 통해 time을 순서대로 정렬해준다.
cnt = 1 
end_time = time[0][1] 
for i in range(1, N): 
	if time[i][0] >= end_time: 
		cnt += 1 
		end_time = time[i][1] 
#cnt를 1로 해준 후, end_time을 time[0][1]로 해준다.
#그다음 1부터 n-1동안 time[i][0]이 end_time보다 크거나 같으면 cnt를 하나 추가해주고, end_time을 바꿔준다.
#이렇게 하면 계속해서 end_time이 바뀌기 때문에 cnt의 수가 어떻게 될지를 알 수가 있다.
print(cnt)
