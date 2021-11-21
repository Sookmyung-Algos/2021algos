k = int(input())
for i in range(k):
    ban = list(map(int, input().split()))
    n = ban[0]
    ban = ban[1:]
    ban.sort()
    dif = []
    for j in range(n-1):
        dif.append(ban[j+1]-ban[j])
    print("Class %d" %(i+1))
    print("Max %d, Min %d, Largest gap %d" %( ban[n-1], ban[0], max(dif)))
