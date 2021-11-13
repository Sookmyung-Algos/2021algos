#include<iostream>
#include<queue>
 
#define endl "\n"
#define MAX 100010
using namespace std;
 
int N;
int Arr[MAX];
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> Arr[i];
}
 
void Solution()
{
    priority_queue<int> Max_PQ, Min_PQ;
    for (int i = 0; i < N; i++)
    {
        if (Max_PQ.size() > Min_PQ.size()) Min_PQ.push(-Arr[i]);
        else Max_PQ.push(Arr[i]);
        
        if (Max_PQ.empty() == false && Min_PQ.empty() == false)
        {
            if (Max_PQ.top() > -Min_PQ.top())
            {
                int Max_Value = Max_PQ.top();
                int Min_Value = -Min_PQ.top();
 
                Max_PQ.pop(); Min_PQ.pop();
                
                Max_PQ.push(Min_Value);
                Min_PQ.push(-Max_Value);
            }
        }
        cout << Max_PQ.top() << endl;
    }
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    Solve();
    return 0;
}
