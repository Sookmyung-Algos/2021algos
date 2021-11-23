#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1e9
#define MAX 101

int n, m;
int arr[MAX][MAX], route[MAX][MAX];
vector<int> v;

void floyd_warshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i == j) continue;
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					arr[j][k] = arr[j][i] + arr[i][k];
					route[j][k] = i;
				}
			}
		}
	}
}

void find(int s, int e) {
	if (route[s][e] == 0) { // 더 이상 거쳐갈 정점x
		v.push_back(s);
		v.push_back(e);
		return;
	}
	find(s, route[s][e]);
	v.pop_back();
	find(route[s][e], e);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] > c) arr[a][b] = c;
	}
	floyd_warshall();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || arr[i][j] == INF) cout << 0 << " ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || arr[i][j] == INF) cout << 0;
			else {
				v.clear();
				find(i, j);
				cout << v.size() << " ";
				for (int k = 0; k < v.size(); k++) {
					cout << v[k] << " ";
				}
			}
			cout << "\n";
		}
	}
}
