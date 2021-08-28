#include <iostream>
 
#define endl "\n"
#define MAX 110

using namespace std;
 
int N;
long long DP[MAX];
 
void input() {
    cin >> N;
}
 
void sol() {
    DP[1] = DP[2] = DP[3] = 1;
    DP[4] = DP[5] = 2;
    for (int i = 6; i <= N; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 5];
    }
    cout << DP[N] << endl;
}
 
void Solve() {
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Input();
        sol();
    }
}
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
 
    return 0;
}
