#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int N,M;
int graph[101][101];
int a, b;
void floydWarshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] == 1 && graph[k][j] == 1)
					graph[i][j] = 1;
				else if (graph[i][k] == -1 && graph[k][j] == -1)
					graph[i][j] = -1;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = -1;
	}
	floydWarshall();
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 0)
				cnt++;
		}
		cout << cnt - 1 << "\n";
	}
}
