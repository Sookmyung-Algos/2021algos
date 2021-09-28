from sys import stdin
n = int(input())
milk = list(map(int, stdin.read().split())) # 가격입력
milk.sort(reverse=True) # 내림차순 정렬
cost = 0
for i in range(n):
    if(i%3!=2): # 3 나누었을 때 나머지가 2이면 가격에 포함하지 않음
        cost += milk[i]
print(cost)
