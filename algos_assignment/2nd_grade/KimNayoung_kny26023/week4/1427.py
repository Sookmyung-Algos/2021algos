nums = input()
nums = [int(n)  for n in nums]
#숫자들을 int형으로 바꿔 nums 배열을 만든다.

ordered_nums = sorted(nums, reverse=True)
#ordered_nums에 sorted(nums, reverse=True)를 넣어준다. 내림차순이기 때문에 그러하다.

for n in ordered_nums : 
    print(n, end="")
