#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001

using namespace std;

vector<int> g[MAX];
int check[MAX];
queue<int> q;

int bfs(int start) {
	int cur, next;
	q.push(start);
	check[start] = 1;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0; i < g[cur].size(); i++) {
			next = g[cur][i];
			if (!check[next]) {
				check[next] = check[cur] * (-1);
				q.push(next);
			}
			else if (check[next] == check[cur])
				// 인접 노드와 숫자가 같으면 이분 그래프가 아님
				return 0;
		}
	}
	return 1;
}

int main() {
	int k, v = 0, e, x, y, ans;
	cin >> k;
	while (k--) {
		ans = 1;
		for (int i = 1; i <= v; i++) {
			while (!g[i].empty())
				g[i].pop_back();
			check[i] = 0;
		}
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for (int i = 1; i <= v; i++) {
			if (!check[i])
				if (!bfs(i)) ans = 0;
		}
		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
