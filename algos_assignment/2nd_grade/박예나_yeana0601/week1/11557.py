T = int(input())
for i in range(T):
    N = int(input())
    n = []
    v = []
    for i in range(N):
        m = input().split()
        n.append(m[0])
        v.append(int(m[1]))
    for i in range(N):
        if sorted(v)[N-1] == v[i]:
            print(n[i])    
