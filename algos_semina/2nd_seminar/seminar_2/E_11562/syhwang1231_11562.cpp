#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAX 251

using namespace std;

int path[MAX][MAX];  // 저장되는 값은 양방향으로 바꿔야하는 길의 개수

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;  // n: 건물 수, m: 길의 수, k: 질문의 수
	int u, v, b;

	scanf("%d %d",&n, &m);
	for (int i = 1; i <= n; i++) {  // 인접행렬 초기화
		for (int j = 1; j <= n; j++) {
			if (i == j)  // 대각선
				path[i][j] = 0;
			else
				path[i][j] = MAX;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &b);  // u에서 v
		path[u][v] = 0;
		if (b == 1)
			path[v][u] = 0;
		else {
			path[v][u] = 1;
		}
	}
	
	for (int k = 1; k <= n; k++) {  // path 전체를 돌면서 비용 행렬 갱신
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) { 
				path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
			}
		}
	}
	scanf("%d", &k);

	int s, e;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &s, &e);
		printf("%d\n", path[s][e]);
	}
	return 0;
}
