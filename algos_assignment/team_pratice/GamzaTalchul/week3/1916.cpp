#include <iostream>
#include <vector>
#include <queue>
 
#define PAIR pair<int, int>
 
using namespace std;
 
vector<pair<int, int>> a[1001];
int d[1001];
bool chk[1001];
 
int main() {
    cin.tie(0);
	ios::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y, z));
    }
    int start, end;
    cin >> start >> end;
    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
    d[start] = 0;
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> q;
    q.push(make_pair(0, start));
    while (!q.empty()) {
        int node = q.top().second;
        q.pop();
        if (!chk[node]) {
            chk[node] = true;
            for (int k = 0; k < a[node].size(); k++) {
                int next = a[node][k].first;
                if (d[next] > d[node] + a[node][k].second) {
                    d[next] = d[node] + a[node][k].second;
                    q.push(make_pair(d[next], next));
                }
            }
        }
    }
    cout << d[end];
}
