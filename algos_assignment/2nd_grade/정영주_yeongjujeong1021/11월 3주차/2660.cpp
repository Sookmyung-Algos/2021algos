#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int dist[51][51];
int arr[51];
vector<int> ans;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int n, a, b; cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;
		dist[i][i] = 0;
	}
	while (true) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF) arr[i] = max(arr[i], dist[i][j]);
		}
	}

	int ans_min = INF;
	for (int i = 1; i <= n; i++) {
		if (ans_min > arr[i]) {
			ans.clear();
			ans.push_back(i);
			ans_min = arr[i];
		}
		else if (ans_min == arr[i]) ans.push_back(i);
	}

	cout << ans_min << ' ' << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}
