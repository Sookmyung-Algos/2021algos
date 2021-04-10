#include <iostream>
#include <algorithm>

#define INF 500000

using namespace std;

int n, m;
int graph[101][101];

void FW() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = graph[j][i] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = INF;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	init();

	int a, b;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	FW();

	int min = INF, ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += graph[i][j];
		}
		if (sum < min) {
			min = sum;
			ans = i;
		}
	}

	cout << ans;
	return 0;
}
