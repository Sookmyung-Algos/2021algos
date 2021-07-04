#include <iostream>
using namespace std;

int ans[251][251];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
	int n, m, u, v, b, t, s, e;
    
	cin >> n >> m;
    
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans[i][j] = (i == j) ? 0 : 300;
    
	while (m--) {
		cin >> u >> v >> b;
		ans[u][v] = 0;
		ans[v][u] = b ? 0 : 1;
	}
    
	for (int k = 1; k <= n; k++) // 거쳐가는 건물 번호
		for (int i = 1; i <= n; i++) // 출발하는 건물 번호
			for (int j = 1; j <= n; j++) // 도착하는 건물 번호
				ans[i][j] = min(ans[i][k] + ans[k][j], ans[i][j]);
    
	cin >> t;
	while (t--) {
		cin >> s >> e;
		cout << ans[s][e] << '\n';
	}

	return 0;
}
