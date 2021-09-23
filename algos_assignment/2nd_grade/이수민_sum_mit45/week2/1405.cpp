#include<iostream>

#define MAX 29 // 14*2보다 크게
using namespace std;

int N;
double Percent[4];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

double DFS(int x, int y, int Cnt) // 깊이우선탐색
{
    if (Cnt == N) 
        return 1.0;

    Visit[x][y] = true;
    double Result = 0.0;

    // 연결리스트
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (Visit[nx][ny] == true) continue;
        Result = Result + Percent[i] * DFS(nx, ny, Cnt + 1);
    }

    Visit[x][y] = false;
    return Result;
}

int main(void)
{
    // 시간 초과
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> N;
    for (int i = 0; i < 4; i++)
    {
        int a; cin >> a;
        Percent[i] = a / 100.0;
    }

    double R = DFS(14, 14, 0);
    cout.precision(10); // 소수점 고정
    cout << fixed << R << '\n';

    return 0;
}
