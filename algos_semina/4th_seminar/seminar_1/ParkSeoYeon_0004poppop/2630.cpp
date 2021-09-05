// 백준 2630 색종이 만들기

#include <iostream>
using namespace std;

int n;
int arr[128][128];
int white, blue;

void count(int y, int x, int size)
{
    int bw = arr[y][x]; // 색 비교를 위한 값 저장

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {

            if (bw == 0 && arr[i][j] == 1)
            {
                bw = 2; // 두 칸이 다른 색임
            }
            else if (bw == 1 && arr[i][j] == 0)
            {
                bw = 2; // 두 칸이 다른 색임
            }
            if (bw == 2)
            {
                count(y, x, size / 2);
                count(y, x + size / 2, size / 2);
                count(y + size / 2, x, size / 2);
                count(y + size / 2, x + size / 2, size / 2);
                return;    // 시간초과하지 않기 위해 필요함
            }   // 좌우상하 각 4개 사분면을 탐색
        }
    }

    // 잘라진 종이들의 색
    if (bw == 0)
        white++;
    else
        blue++;
}
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    count(0, 0, n);

    cout << white << '\n';
    cout << blue << '\n';
    return 0;
}
