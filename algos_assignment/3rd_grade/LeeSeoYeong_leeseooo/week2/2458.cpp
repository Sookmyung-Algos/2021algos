#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int graph[501][501];
int N, M;
int a, b;
void floydWS() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] == 1 && graph[k][j] == 1)
					//i가 k보다 나중 k가 j보다 나중이면 i는 j보다 나중
					graph[i][j] = 1;
				else if (graph[i][k] == -1 && graph[k][j] == -1)
					//i가 k보다 먼저 k가 j보다 먼저면 i는 j보다 먼저
					graph[i][j] = -1;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = -1;
		graph[b][a] = 1;
	}
	floydWS();
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int zeroCnt = 0;
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 0)
				zeroCnt++;
		}
		if (zeroCnt == 1)
			ans++;
	}
	cout << ans;
}
