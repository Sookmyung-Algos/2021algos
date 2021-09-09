from sys import stdin
n, m= map(int, stdin.readline().split())
pokemon= []
index= {}
for i in range(n):
    poke= stdin.readline().rstrip()
    pokemon.append(poke)
    index[poke]= i+1
for i in range(m):
    problem= stdin.readline().rstrip()
    if(problem.isnumeric()):
        print(pokemon[int(problem)-1])
    else:
        print(index[problem])
