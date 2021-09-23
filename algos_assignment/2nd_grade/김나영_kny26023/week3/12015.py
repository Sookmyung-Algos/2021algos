import sys  

N = int(sys.stdin.readline()) 
A = list(map(int, sys.stdin.readline().split())) 
stack = [0] 
#A라는 배열과 stack이라는 배열을 하나 만든다.

def search(target): 
	left, right = 1, len(stack)-1 
	while left < right: 
		mid = (left+right) // 2 
		if stack[mid] < target: 
			left = mid+1 
		elif stack[mid] > target: 
			right = mid 
		else: 
			left = right = mid 
	return right
#이분탐색 알고리즘을 써서 search해준다.

for ai in A:
	if stack[-1] < ai: 
		stack.append(ai) 
    #stack의 마지막 원소가 ai보다 작을 때, stack에 ai를 append해준다.
	else: 
		stack[search(ai)] = ai 
    #아닐 경우 stack[search(ai)]에 ai를 넣어준다.

print(len(stack)-1)
#stack의 길이에서 하나를 뺀 값을(0을 넣었기 때문에) 출력하면 답이 나오게 된다.
