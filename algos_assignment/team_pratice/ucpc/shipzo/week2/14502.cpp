#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

#define MAX 8

using namespace std;

int N, M;
int Space, Answer;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
bool Check[MAX * MAX];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<int, int>> Empty, Virus;

int bigger(int A, int B) { if (A > B) return A; return B; }

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 0) Empty.push_back(make_pair(i, j));
            else if (MAP[i][j] == 2) Virus.push_back(make_pair(i, j));
        }
    }
    Space = Empty.size();
}

void Copy_MAP()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            C_MAP[i][j] = MAP[i][j];
        }
    }
}

void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (Visit[nx][ny] == false && C_MAP[nx][ny] == 0)
                {
                    C_MAP[nx][ny] = 2;
                    Visit[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int Count_Safe_Area()
{
    int Cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (C_MAP[i][j] == 0) Cnt++;
        }
    }
    return Cnt;
}

void Spread_Virus()
{
    int Cnt = 0;
    Copy_MAP();
    memset(Visit, false, sizeof(Visit));

    for (int i = 0; i < Space; i++)
    {
        if (Cnt == 3) break;
        if (Check[i] == true)
        {
            int x = Empty[i].first;
            int y = Empty[i].second;
            C_MAP[x][y] = 1;
            Cnt++;
        }
    }

    for (int i = 0; i < Virus.size(); i++)
    {
        int x = Virus[i].first;
        int y = Virus[i].second;
        BFS(x, y);
    }

    int Temp_Answer = Count_Safe_Area();
    Answer = bigger(Answer, Temp_Answer);
}

void Make_Wall(int Idx, int Cnt)
{
    if (Cnt == 3)
    {
        Spread_Virus();
        return;
    }

    for (int i = Idx; i < Space; i++)
    {
        if (Check[i] == true) continue;
        Check[i] = true;
        Make_Wall(i, Cnt + 1);
        Check[i] = false;
    }
}

void Solution()
{
    Make_Wall(0, 0);
}

void Solve()
{
    Input();
    Solution();
    cout << Answer;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
