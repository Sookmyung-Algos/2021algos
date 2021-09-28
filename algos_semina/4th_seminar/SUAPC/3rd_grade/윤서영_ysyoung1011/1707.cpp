#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

vector <int> v[20001];
int check[20001];
queue <int> q;

void bfs(int x) {
	check[x] = 1;
	q.push(x);

	while (!q.empty()) {
		int k = q.front(); q.pop();
	
		for (int i = 0; i < v[k].size(); i++) {
			int y = v[k][i];
			if (check[y] == 0) {
				check[y] = 3 - check[k];
				q.push(y);
			}
		}
	}
}

int main() {
	int k;
	cin >> k;
	while (k--) {
		int n, m;
		cin >> n >> m;
		memset(check, 0, sizeof(check));
		for (int i = 0; i <= n; i++) v[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) bfs(i);
		}

		int flag = 0;
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < v[i].size(); k++) {
				int j = v[i][k];
				if (check[i] == check[j]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
