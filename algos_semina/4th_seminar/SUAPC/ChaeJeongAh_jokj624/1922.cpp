//AC
//BOJ 1922 네트워크 연결
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define MAX 1010
typedef long long ll;
struct edge {
    int start, end, cost;
};
bool cmp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}
int n, k;
int parent[MAX];
vector<edge> v;
int Find(int x) {
    if (x == parent[x])
        return x;
    parent[x] = Find(parent[x]);
    return parent[x];
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}
void mst() {
    ll ans = 0;
    for (edge e : v) {
        int st = e.start;
        int ed = e.end;
        if (Find(st) != Find(ed)) {
            ans += e.cost;
            Union(Find(st), Find(ed));
        }
    }
    cout << ans;
}
int main() {
    int tmp;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= k; i++) {
        int s, e, c;
        scanf("%d %d %d", &s, &e, &c);
        v.push_back({s, e, c});
    }
    sort(v.begin(), v.end(), cmp);
    mst();
    return 0;
}