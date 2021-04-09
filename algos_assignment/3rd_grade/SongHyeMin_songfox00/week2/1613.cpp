#include<iostream>
#define INF 10000000

using namespace std;

int n, k, a, b, c;
int graph[401][401];

void floydWarshall() {
	for (int i = 1; i <= n; i++) {	//중간
		for (int j = 1; j <= n; j++) {	//출발
			for (int k = 1; k <= n; k++) {	//도착
				if (graph[j][i] == 1 && graph[i][k] == 1)	//j가 i보다 늦게, i가 k보다 늦게 일어난 사건이면
					graph[j][k] = 1;	//j가 k보다 늦게
				else if (graph[j][i] == -1 && graph[i][k] == -1)	//j가 i보다 일찍, i가 k보다 일찍 일어난 사건이면
					graph[j][k] = -1;	//j가 k보다 일찍
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= k; i++) {	//초기화
		int a, b;
		cin >> a >> b;
		graph[a][b] = -1;
		graph[b][a] = 1;
	}
	floydWarshall();

	int s;
	cin >> s;

	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		cout << graph[a][b]<<'\n';
	}
	return 0;
}
