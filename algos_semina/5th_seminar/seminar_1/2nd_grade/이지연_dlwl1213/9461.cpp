#include <iostream>
 
#define endl "\n"
#define MAX 110
using namespace std;
 
int N;
long long DP[MAX];
 
void Input(){
    cin >> N;
}
 
void Solution(){
    DP[1] = DP[2] = DP[3] = 1;
    DP[4] = DP[5] = 2;
    for (int i = 6; i <= N; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 5];
    }
    cout << DP[N] << endl;
}
 
void Solve(){
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Input();
        Solution();
    }
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
