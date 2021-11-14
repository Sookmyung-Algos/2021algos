#include <iostream>
#define INF 1e9
using namespace std;

int n, m, x;
int dist[201][201];
int mid[201][201];

void floydwarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					mid[i][j] = k;
				}
			}
		}
	}
}

void find(int l, int r) {
	if (mid[l][r] == 0) cout << r << ' ';
	else find(l, mid[l][r]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	floydwarshall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else find(i, j);
		}
		cout << '\n';
	}

	return 0;
}
