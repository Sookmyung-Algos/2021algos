//1389 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int graph[101][101] = { 0, };
int cnt[101], ans = MAX, idx;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else if (graph[i][j] == 0) graph[i][j] = MAX;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
		for (int j = 1; j <= n; j++)
			cnt[i] += graph[i][j];
		if (cnt[i] < ans) {
			ans = cnt[i];
			idx = i;
		}

	}
	cout << idx;
}
