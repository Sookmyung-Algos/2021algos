#include <iostream>
#include <stack>
#include <vector>
#define INF 1e9
using namespace std;

int bus[101][101];
int path[101][101];

vector<int> v;

void getPath(int s, int e) {
	if (!path[s][e]) return;
	else {
		getPath(s, path[s][e]);
		v.push_back(path[s][e]);
		getPath(path[s][e], e);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) bus[i][j] = INF;
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		bus[a][b] = min(bus[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (bus[i][j] > bus[i][k] + bus[k][j]) {
					bus[i][j] = bus[i][k] + bus[k][j];
					path[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bus[i][j] == INF) cout << "0 ";
			else cout << bus[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) { // 출발 도시
		for (int j = 1; j <= n; j++) { // 도착 도시
			if (bus[i][j] == INF) {
				cout << "0\n";
				continue;
			}
			v.clear();
			getPath(i, j);
			cout << 2 + v.size() << ' ' << i << ' ';
			for (int k = 0; k < v.size(); k++) cout << v[k] << ' ';
			cout << j << " \n";
		}
	}

	return 0;
}
