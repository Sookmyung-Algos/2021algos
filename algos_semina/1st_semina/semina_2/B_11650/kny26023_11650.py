N = int(input())
nums = []
for i in range(N): 
    [x, y] = map(int, input().split()) 
    nums.append([x, y])
    #nums라는 배열에 [x,y]를 넣어준다.
nums = sorted(nums) 
#nums를 sort한다.
for i in range(N): 
    print(nums[i][0], nums[i][1])
    #sort된 nums에서 x,y를 각각 프린트한다.
