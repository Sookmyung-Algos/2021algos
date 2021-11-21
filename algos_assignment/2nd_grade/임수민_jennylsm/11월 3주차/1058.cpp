#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int a[54][54], n, _max, ret;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    fill(&a[0][0], &a[0][0] + 54 * 54, INF);
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 1; j <= s.size(); j++){
            if(s[j - 1] == 'Y') a[i][j] = 1;
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(a[i][j] == 1 || a[i][j] == 2)cnt++;
        }
        _max = max(_max, cnt);
    }
    cout << _max << "\n";
    return 0;
}
