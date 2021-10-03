#include <iostream>
#include <algorithm>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int t, a, b;
bool visit[10001];
void solve() {
	queue<pair<int, string>>q;
	q.push({ a,"" });
	visit[a] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		string op = q.front().second;
		q.pop();

		if (cur == b) {
			cout << op << '\n';
			return;
		}
		int tmp = (cur * 2) % 10000;
		if (!visit[tmp]) {
			q.push({ tmp,op + 'D' });
			visit[tmp] = true;
		}
		tmp = cur - 1 < 0 ? 9999 : cur - 1;
		if (!visit[tmp]) {
			visit[tmp] = true;
			q.push({ tmp,op + 'S' });
		}
		tmp = cur / 1000 + (cur % 1000) * 10;
		if (!visit[tmp]) {
			visit[tmp] = true;
			q.push({ tmp,op + 'L' });
		}
		tmp = cur / 10 + (cur % 10) * 1000;
		if (!visit[tmp]) {
			visit[tmp] = true;
			q.push({ tmp,op + 'R' });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(visit, false, sizeof(visit));
		cin >> a >> b;
		solve();
	}
}
