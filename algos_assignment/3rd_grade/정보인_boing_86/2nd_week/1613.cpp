#include <iostream>
#include <algorithm>

using namespace std;

int n;
int graph[401][401] = { 0, };

void FW() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] == 1 && graph[k][j] == 1)
					graph[i][j] = 1;
				else if (graph[i][k] == -1 && graph[k][j] == -1)
					graph[i][j] = -1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k, a, b;

	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		cin >> a >> b;
		graph[a][b] = -1;
		graph[b][a] = 1;
	}

	FW();

	int s;
	cin >> s;

	for (int i = 1; i <= s; i++) {
		cin >> a >> b;
		cout << graph[a][b] << "\n";
	}
}
