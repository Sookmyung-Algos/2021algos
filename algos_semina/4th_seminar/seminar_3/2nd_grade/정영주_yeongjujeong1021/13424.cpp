#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 100000001
using namespace std;

int fr[101];
long long dist[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, m, k;
	cin >> t;
	while (t--) {
		int r = 0;
		long long sum = INF;
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				dist[i][j] = INF;
			dist[i][i] = 0;
		}

		for (int i = 0, a, b, c; i < m; i++) {
			cin >> a >> b >> c;
			dist[a][b] = c;
			dist[b][a] = c;
		}

		cin >> k;
		for (int i = 0; i < k; i++) cin >> fr[i];
		
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (dist[i][k] + dist[k][j] < dist[i][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						dist[j][i] = dist[i][j];
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			long long tmp = 0;
			for (int j = 0; j < k; j++)
				tmp += dist[fr[j]][i];
			if (tmp < sum) {
				sum = tmp; r = i;
			}
		}

		cout << r << '\n';
	}

	return 0;
}
