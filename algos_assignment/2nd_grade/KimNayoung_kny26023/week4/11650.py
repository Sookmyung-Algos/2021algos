N = int(input())
nums = []
for i in range(N): 
    [a, b] = map(int, input().split()) 
    nums.append([a, b])
    #nums에 (a,b)를 append해준다.
        
nums = sorted(nums) 
#nums를 sort해준다
        
for i in range(N): 
    print(nums[i][0], nums[i][1])
