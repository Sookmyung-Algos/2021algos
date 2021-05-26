nums = input()
nums = [int(n)  for n in nums]
#숫자들을 int형으로 바꿔 nums 배열을 만든다.

order = sorted(nums, reverse=True)
#order에 sorted(nums, reverse=True)를 넣어준다. 내림차순이기 때문에 그러하다.

for n in order : 
    print(n, end="")
https://github.com/kny26023/2021algos/blob/patch-27/algos_assignment/2nd_grade/KimNayoung_kny26023/week4/1427.py
