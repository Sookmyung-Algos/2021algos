//AC
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef unsigned long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ll N, K;
        ll ans = 0;
        cin >> N >> K;
        if (N < K) {
            K = N;
        }
        ans += (((2*N*(K+1) - (K*(K+1)))) * 2);
        cout << ans << "\n";
    }   

    return 0;
}
