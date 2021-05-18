n = int(input())

s = list(map(int, input().split()))
#s라는 배열을 만들어 input되는 것들을 추가해준다.
time = 0
#time이라는 변수를 하나 만든다.
s.sort()
#s를 오름차순으로 정렬한다.
for i in range(n):
    for j in range(i + 1):
        time += s[j]
        #오름차순으로 정렬한 것을 이중 for문 내에서 time에 더해준다.
print(time)
#저렇게 더하게 되면 time에 정답이 들어가게 된다.
