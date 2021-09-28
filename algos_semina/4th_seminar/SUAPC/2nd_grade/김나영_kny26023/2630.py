from sys import stdin
input= stdin.readline

n= int(input())
paper= []
for i in range(n):
    temp= list(map(int, input().split()))
    paper.append(temp)
result= []

def solution(x, y, n) :
  color= paper[x][y]
  for i in range(x, x+n) :
    for j in range(y, y+n) :
      if color!=paper[i][j] :
        solution(x, y, n//2)
        solution(x, y+n//2, n//2)
        solution(x+n//2, y, n//2)
        solution(x+n//2, y+n//2, n//2)
        return
  if color == 0 :
    result.append(0)
  else :
    result.append(1)


solution(0, 0, n)
print(result.count(0))
print(result.count(1))
