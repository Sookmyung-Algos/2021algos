//11562 백양로 브레이크
#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int n, m;
int graph[251][251] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)graph[i][j] = 0;
			else graph[i][j] = MAX;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, b;
		cin >> u >> v >> b;
		//양방향 통행으로 바꿔야 하는 곳=1, 이미 양방향인 곳=0
		if (b == 0) {
			graph[v][u]=1;
			graph[u][v] = 0;
		}
		else {
			graph[u][v] = 0;
			graph[v][u] = 0;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
			}
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		cout << graph[u][v] << '\n';
	}
}
