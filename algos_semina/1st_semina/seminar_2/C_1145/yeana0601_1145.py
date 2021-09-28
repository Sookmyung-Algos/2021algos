x = list(map(int, input().split()))
n = min(x)

while True:
    count = 0
    for i in range(5):
        if n%x[i] == 0:
            count +=1
    if count > 2:
        print(n)
        break
    n += 1
    
