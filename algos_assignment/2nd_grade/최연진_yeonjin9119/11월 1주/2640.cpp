#include <iostream>

using namespace std;

int n;
int paper[128][128];
int blue, white;

void solve(int y, int x, int size)
{
    int check = paper[y][x];
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {

            if (check == 0 && paper[i][j] == 1)
            {
                check = 2;
            }
            else if (check == 1 && paper[i][j] == 0)
            {
                check = 2;
            }
            if (check == 2)
            {
                solve(y, x, size / 2);
                solve(y, x + size / 2, size / 2);
                solve(y + size / 2, x, size / 2);
                solve(y + size / 2, x + size / 2, size / 2);
                return;
            }
        }
    }
    if (check == 0)
        white++;
    else
        blue++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];

    solve(0, 0, n);
    cout << white << '\n';
    cout << blue << '\n';
    return 0;
}
