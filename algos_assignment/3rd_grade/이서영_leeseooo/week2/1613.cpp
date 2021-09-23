#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int graph[401][401];
int n, k;
int a, b;
void floydWS() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
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
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = -1;
		graph[b][a] = 1;
	}
	floydWS();
	int s;
	scanf("%d ", &s);
	for (int i = 0; i < s; i++) {
		int e1, e2;
		scanf("%d %d", &e1, &e2);
		printf("%d\n", graph[e1][e2]);
	}
}
