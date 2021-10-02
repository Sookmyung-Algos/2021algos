#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m, c1, c2;
vector <pair<int,int>> v;

int main() {
    // 입력
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> c1 >> c2;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(make_pair(a, c1));
    }
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        v.push_back(make_pair(a, c2));
    }

    sort(v.begin(), v.end()); // x값이 작은대로 정렬
    
    long long cnt=0;
    long long mmin = pow(10, 9);

    for (int i = 0; i < n + m -1 ; i++) { // 앞, 뒤
        int x1, x2, y1, y2;
        x1 = v[i].first; y1 = v[i].second;
        x2 = v[i + 1].first; y2 = v[i + 1].second;
        int dis = (abs(x1 - x2) + abs(y1 - y2));
        if (y1 != y2 || c1 == c2) {
            if (dis < mmin) {
                mmin = dis;
                cnt = 1;
            }
            else if (dis == mmin) {
                cnt++;
            }
        }
    }

    cout << mmin << " " << cnt;
    return 0;
}
