#include<iostream>
#include<vector>
#include<cstring>

#define MAX 901
using namespace std;
 
int K, N, F;
int FriendNum[MAX];
bool Friend[MAX][MAX];
vector<int> Answer;
bool Select[MAX];
bool Flag = false;
 
void Print()
{
    for (int i = 1; i <= N; i++)
    {
        if (Select[i] == true) cout << i << "\n";
    }
}
 
bool CanSelect(int x)
{
    for (int i = 1; i <= N; i++)
    {
        if (Select[i] == true)
        {
            if (Friend[x][i] == false) return false;
        }
    }
    return true;
}
 
void dfs(int Cur, int Cnt)
{
    if (Flag == true) return;
    if (Cnt == K)
    {
        Print();
        Flag = true;
        return;
    }
 
    for (int i = Cur + 1; i <= N; i++)
    {
        if (Friend[Cur][i] == false) continue;
        if (CanSelect(i) == false) continue;
        Select[i] = true;
        dfs(i, Cnt + 1);
        Select[i] = false;
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
        cin >> K >> N >> F;
    for (int i = 0; i < F; i++)
    {
        int a, b;
        cin >> a >> b;
        Friend[a][b] = true;
        Friend[b][a] = true;
 
        FriendNum[a]++;
        FriendNum[b]++;
    }
    
    for (int i = 1; i <= N; i++)
    {
        if (FriendNum[i] < K - 1) continue;
        if (Flag == true) break;
        
        Select[i] = true;
        dfs(i, 1);
        Select[i] = false;
    }
 
    if (Flag == false) cout << -1 << "\n";
 
    return 0;
}
