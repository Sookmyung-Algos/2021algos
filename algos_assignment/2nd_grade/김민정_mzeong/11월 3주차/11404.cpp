#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9
#define MAX 101

int n, m;
int arr[MAX][MAX];

void floyd_warshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][i] != INF && arr[i][k] != INF) {
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
				}
			}
		}
	}
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
}
