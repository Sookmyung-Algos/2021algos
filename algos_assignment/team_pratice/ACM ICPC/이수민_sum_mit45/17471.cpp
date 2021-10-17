#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
 
#define endl "\n"
#define MAX 10 + 1
using namespace std;
 
int N, Answer = 987654321;
int Person[MAX];        // 인구수를 저장하기 위한 배열
bool Connect[MAX][MAX];    // 구역들 간의 연결관계를 저장하기 위한 배열
bool Select[MAX];        // 조합 구현 시, 뽑은 데이터에 대한 체크를 저장하기 위한 배열
bool Visit[MAX];        // BFS탐색 시, 방문 탐색을 체크하기 위한 배열

bool Check_Connection(vector<int> V, bool T){
    memset(Visit, false, sizeof(Visit));
    queue<int> Q;
    Q.push(V[0]);        
    Visit[V[0]] = true;
    int Cnt = 1;
 
    while (Q.empty() == 0)
    {
        int x = Q.front();
        Q.pop();
 
        for (int i = 1; i <= N; i++)
        {
            if (Connect[x][i] == true && Select[i] == T && Visit[i] == false)
            {
                Visit[i] = true;
                Cnt++; 
                Q.push(i);
            }
        }
    }
    if (V.size() == Cnt) return true;
    return false;
}
 
bool Check(){ vector<int> A, B;
    for (int i = 1; i <= N; i++)
    {
        if (Select[i] == true) A.push_back(i); 
        else B.push_back(i);                   
    }

    if (A.size() == 0 || B.size() == 0) return false;
 
    bool AState = Check_Connection(A, true);
    if (AState == false) return false;
 
    bool BState = Check_Connection(B, false);
    if (BState == false) return false;
 
    return true;
}
 
void Calculate(){
    int A_Num, B_Num, Diff;
    A_Num = B_Num = 0;
 
    for (int i = 1; i <= N; i++)
    {
        if (Select[i] == true) A_Num = A_Num + Person[i];
        else B_Num = B_Num + Person[i];
    }
    Diff = abs(A_Num - B_Num);
    if (Answer > Diff) Answer = Diff;
}
 
void DFS(int Idx, int Cnt){
    if (Cnt >= 1){
        if (Check() == true){
            Calculate();
        }
    }
 
    for (int i = Idx; i <= N; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
   cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int x; cin >> x;
        Person[i] = x;
    }
    for (int i = 1; i <= N; i++)
    {
        int Cnt; cin >> Cnt;
        for (int j = 0; j < Cnt; j++)
        {
            int a; cin >> a;
            Connect[i][a] = true;
            Connect[a][i] = true;
        }
    }
    
    DFS(1, 0);     
 
    if (Answer == 987654321) cout << -1 << endl;
    else cout << Answer << endl;
 
    return 0;
}
