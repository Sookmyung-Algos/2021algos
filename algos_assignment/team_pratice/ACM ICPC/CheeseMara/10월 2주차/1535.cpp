#include <iostream>
#include <algorithm>
using namespace std;
int n, l[22], j[22], d[22][101];

int go(int pos, int hp) {
    if (pos == n)
        return 0;
    int ret = d[pos][hp];
    if (ret != -1) 
        return ret;
    ret = go(pos + 1, hp);
    if (hp - l[pos] > 0) 
        ret = max(ret, go(pos + 1, hp - l[pos]) + j[pos]);
    return ret;
}
 
int main() {
    memset(d, -1, sizeof(d));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> l[i];
    }
    for (int i = 0; i < n; i++){
        cin >> j[i];
    }
    cout << go(0, 100) << "\n";
}
