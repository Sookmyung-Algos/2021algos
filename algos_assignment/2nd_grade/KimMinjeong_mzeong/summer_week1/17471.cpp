#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int p[11];
int connect[11][11];
bool selection[11];
int n, ans = 1000;

bool bfs(vector<int> v, bool group) {
	if (v.size() == 0) return false; // 선거구는 구역을 적어도 하나 포함해야 함

	bool mark[11] = { false };
	queue<int> q;

	mark[v[0]] = true;
	q.push(v[0]);
	int cnt = 1;

	while (!q.empty()) {
		int temp = q.front(); q.pop();
		for (int i = 1; i <= n; i++) {
			// 같은 그룹이어야 하고, 연결되어 있어야 하고, 방문한 적 없어야 함
			if (selection[i] == group && connect[temp][i] && !mark[i]) {
				mark[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}
	if (v.size() == cnt) return true;
	else return false;
}

void dfs(int idx, int cnt) {
	if (cnt >= 1) {
		vector<int> A, B;
		for (int i = 1; i <= n; i++) {
			if (selection[i]) A.push_back(i);
			else B.push_back(i);
		}
		if (bfs(A, true) && bfs(B, false)) {
			int sum_A = 0, sum_B = 0;
			for (int i = 0; i < A.size(); i++) sum_A += p[A[i]];
			for (int i = 0; i < B.size(); i++) sum_B += p[B[i]];
			ans = min(ans, abs(sum_A - sum_B));
		}
	}

	for (int i = idx; i <= n; i++) {
		if (selection[i]) continue;
		selection[idx] = true;
		dfs(i, cnt + 1);
		selection[idx] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int a; cin >> a;
			connect[i][a] = 1;
			connect[a][i] = 1;
		}
	}

	dfs(1, 0);

	if (ans == 1000) cout << -1;
	else cout << ans;
}
