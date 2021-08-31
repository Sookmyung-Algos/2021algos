import sys
input = sys.stdin.readline

n = int(input())
a, b = map(int, input().split())
dough = int(input())
top = []
for i in range(n):
    top.append(int(input()))
top.sort(reverse=True)
total = dough 
cnt = 0 
money = total//a 
while 1: 
    for j in range(n): 
        total += top[j] 
        cnt += 1 
        n_money = total//(a+(b*cnt)) 
        if money<=n_money: 
            money = n_money 
        else: 
            print(money) 
            exit()
