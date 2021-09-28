//AC
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
vector<ll> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll K;
    int N;
    cin >> N >> K;
    v.resize(N+1);
    for(int i=1; i<=N; i++) {
        cin >> v[i];
    }
    ll sum = 0, res = 0;
    sort(v.begin(), v.end());
    for(int i=1; i<N; i++) {
        sum = (v[1] * i) + v[i+1] * (N - i);
        res = max(res, sum);
    }
    int add = K % res ? 1 : 0;
    cout << (K / res) + add;
    return 0;
}