#include<iostream>
#include<cstring>
 
#define endl "\n"
#define MAX 1000
#define INF 987654321
using namespace std;
 
int N;
int Arr[MAX];
int DP[MAX];
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
int DFS(int Cur)
{
    if (Cur >= N) return INF;
    if (Cur == N - 1) return 0;
    if (DP[Cur] != -1) return DP[Cur];
 
    DP[Cur] = INF;
    for (int i = 1; i <= Arr[Cur]; i++) DP[Cur] = Min(DP[Cur], DFS(Cur + i) + 1);
    
    return DP[Cur];
}
 
void Solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    memset(DP, -1, sizeof(DP));
    int Answer = DFS(0);
    if (Answer == INF) cout << -1 << endl;
    else cout << Answer << endl;
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}
