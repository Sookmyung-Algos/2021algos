from sys import stdin

a, b, c = list(map(int, stdin.readline().rstrip().split()))
x1, x2, y1, y2 = list(map(int, stdin.readline().rstrip().split()))
X = [x1, x2]
Y = [y1, y2]

def graph(bang):
    for x in X :
        for y in Y :
            rect = a*x+b*y+c
            if rect==0:
                print("Lucky")
                return
            if bang==0 and rect>0 :
                bang=1
            elif bang==0 and rect<0 :
                bang=-1
            if rect*bang<0 :
                print("Poor")
                return
    print("Lucky")

graph(0)
