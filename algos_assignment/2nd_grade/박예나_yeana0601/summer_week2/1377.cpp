#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

#define MAX 500001
int a[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, v[i].second - i);

    cout << ans + 1 << '\n';
}

