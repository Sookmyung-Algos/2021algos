#include<iostream>
#define INF 10000000

using namespace std;

int n, m, a, b, c;
int graph[401][401];

void floydWarshall() {
	for (int i = 1; i <= n; i++) {	//중간
		for (int j = 1; j <= n; j++) {	//출발
			for (int k = 1; k <= n; k++) {	//도착
				if (graph[j][k] > graph[j][i] + graph[i][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {	//초기화
		for (int j = 1; j <= n; j++) {
			if (i != j)	//제일 적은 비용이 나으므로 제외
				graph[i][j] = INF;
		}
	}

	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		if (graph[a][b] > c)	//적은 비용 저장
			graph[a][b] = c;
	}
	floydWarshall();

	int res = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (res > graph[i][j] + graph[j][i])
				res = graph[i][j] + graph[j][i];
		}
	}

	if (res == INF)
		cout << -1;
	else
		cout << res;

	return 0;
}
