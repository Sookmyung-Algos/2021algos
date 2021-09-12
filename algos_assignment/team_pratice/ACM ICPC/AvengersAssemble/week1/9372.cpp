#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<vector<int>>v;
bool visit[1001] = { false, };
int cnt;

void dfs(int a) {
	visit[a] = true;

	for (int i = 0; i < v[a].size(); i++) {
		int nxt = v[a][i];
		if (!visit[nxt]) {
			dfs(nxt);
			cnt++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		v.resize(n+1);

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}
		cout << cnt << '\n';
		memset(visit, false, sizeof(visit));
		for (int i = 0; i <= n; i++) {
			v[i].clear();
		}
	}
	
	return 0;
}
