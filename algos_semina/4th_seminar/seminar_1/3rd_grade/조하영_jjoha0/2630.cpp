#include <iostream>
#include <string>

using namespace std;

int b, w;
int map[129][129];

void go(int n, int startX, int startY)
{
    int color = map[startX][startY];
    for (int i = startX; i < startX + n; i++)
    {
        for (int j = startY; j < startY+n; j++)
        {
            if (map[i][j] != color)
            {// 색깔이 다르다면 크기가 n인 정사각형을 이루지 않기 때문에 재귀 호출
                go(n/2, startX, startY);
                go(n/2, startX + n/2, startY);
                go(n/2, startX, startY + n/2);
                go(n/2, startX + n/2, startY + n/2);
                return;
            }
        }
    }
    // 현재와 같은 색깔일 때는 이중 for문을 돌지 않고 해당 색상 스티커 수 증가
    if (color == 1)
        b++;
    else
        w++;
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }
    go(n, 0, 0);
    cout << w << endl << b << endl;
    return 0;
}
