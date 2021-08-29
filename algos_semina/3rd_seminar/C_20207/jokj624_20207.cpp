//AC
//BOJ 20207 달력
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int check[1001][366];
int height[1001];
bool cmp(const pii& a, const pii& b) {
    if (a.first == b.first)     return a.second > b.second;
    return a.first < b.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, h = 0;
    int minS = 366, maxE = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
        minS = min(minS, s);
        maxE = max(maxE, e);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) {
        int s = v[i].first;     
        int e = v[i].second;
        int h = 0;
        for(int j=0; j<=h; j++) {
            if(check[j][s])    h++;
        }
        for(int j=s; j<=e; j++) {
            check[h][j] = 1;
            height[j] = max(height[j], h+1);
        }
    }
    int ans = 0, count = 0, ch = 0, maxHeight = 0;
    for(int i = minS; i<=maxE; i++) {
        if (ch) {
            count = 0;
            maxHeight = 0;
            ch = 0;
        }
        if (height[i]) {
            count++;
            maxHeight = max(maxHeight, height[i]);
        }
        if(!height[i] || i == maxE) {
            ch = 1;
            ans += (count * maxHeight);
        }
    }
    cout << ans;
    return 0;
}