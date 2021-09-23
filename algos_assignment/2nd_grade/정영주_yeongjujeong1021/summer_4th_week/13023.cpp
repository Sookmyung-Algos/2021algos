#include <iostream>
#include <vector>
using namespace std;

vector<int> v[2001];
int visit[2001];

void dfs(int cur, int cnt) {
	if (cnt == 5) {
		cout << "1\n";
		exit(0);
	}

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (!visit[next]) {
			visit[next] = 1;
			dfs(next, cnt + 1);
			visit[next] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		visit[i] = 1;
		dfs(i, 1);
		visit[i] = 0;
	}

	cout << "0\n";

	return 0;
}
