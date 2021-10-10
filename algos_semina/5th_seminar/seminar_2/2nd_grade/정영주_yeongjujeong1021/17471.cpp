#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, ans = -1, arr[11], area[11], visit[11];
vector<int> v[11];

void calc() {
	queue<int> q;

	for (int i = 1; i <= n; i++) visit[i] = area[i];

	for (int i = 1; i <= n; i++) {
		if (area[i] == 1) {
			q.push(i);
			visit[i] = 0;
			break;
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visit[next] == 1) {
				visit[next] = 0;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (visit[i] == 1) return;

	for (int i = 1; i <= n; i++) {
		if (area[i] == 2) {
			q.push(i);
			visit[i] = 0;
			break;
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visit[next] == 2) {
				visit[next] = 0;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (visit[i] == 2) return;

	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (area[i] == 1) a += arr[i];
		else b += arr[i];
	}

	if (ans == -1) ans = abs(a - b);
	else ans = min(ans, abs(a - b));
}

void dfs(int i, int a, int b) {
	if (i == n + 1) {
		if (a && b) calc();
		return;
	}

	area[i] = 1;
	dfs(i + 1, a + 1, b);

	area[i] = 2;
	dfs(i + 1, a, b + 1);

	area[i] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1, m; i <= n; i++) {
		cin >> m;
		for (int j = 1, x; j <= m; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}

	dfs(1, 0, 0);

	cout << ans << '\n';

	return 0;
}
