#include<iostream>
#define INF 10000000

using namespace std;

int n, m;
int graph[501][501];

void floydWarshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {	
				if (graph[j][i] == 1 && graph[i][k] == 1)	//j가 i보다 크고, i가 k보다 크면
					graph[j][k] = 1;	//j가 k보다 크다
				else if (graph[j][i] == -1 && graph[i][k] == -1)	//j가 i보다 작고, i가 k보다 작으면
					graph[j][k] = -1;	//j가 k보다 작다
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {	//초기화
		int a, b;
		cin >> a >> b;
		graph[a][b] = -1;
		graph[b][a] = 1;
	}
	floydWarshall();

	int res = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (graph[i][j] && graph[j][i])
				cnt++;
		}
		if (cnt == n - 1)
			res++;
	}
	cout << res;
	return 0;
}
