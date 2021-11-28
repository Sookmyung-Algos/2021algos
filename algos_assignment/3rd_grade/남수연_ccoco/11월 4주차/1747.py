import sys

num = int(sys.stdin.readline())

while True:
    if str(num) == str(num)[::-1]:
        if num == 1:
            num += 1
        elif num == 2:
            print(num)
            break
        else:
            for i in range(2, num):
                flag = num % i
                if not flag:
                    break
            if not flag:
                num += 1
            else:
                print(num)
                break
    else:
        num += 1
