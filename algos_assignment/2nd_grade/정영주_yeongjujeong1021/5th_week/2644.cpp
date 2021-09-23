#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> v[MAX];
int visit[MAX] = { 0, };

int n, a, b, ans = 0;

void dfs(int start, int cnt, int *visit_temp) {
	if (start == b) ans = cnt;

	for (int i = 1; i <= n; i++)
		visit[i] = visit_temp[i];

	visit[start] = 1;

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!visit[next])
			dfs(next, cnt + 1, visit);
		if (ans) return;
	}

	if (start == a) ans = -1;
}

int main() {
	cin >> n >> a >> b;

	int m, x, y;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	dfs(a, 0, visit);

	cout << ans << '\n';
}
