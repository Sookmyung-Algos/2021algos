#include <iostream>
using namespace std;

void bfs(int p, int q, int b[][50], int m, int n){
	if (!b[p][q])
		return;
	b[p][q] = 0;
	if (p > 0)
		bfs(p - 1, q, b, m, n);
	if (p < m - 1)
		bfs(p + 1, q, b, m, n);
	if (q > 0)
		bfs(p, q - 1, b, m, n);
	if (q < n - 1)
		bfs(p, q + 1, b, m, n);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		int m, n, k, b[50][50] = {}, ans = 0;
		scanf("%d%d%d", &m, &n, &k);
		while (k--) {
			int p, q;
			scanf("%d %d", &p, &q);
			b[p][q] = 1;
		}
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				if (b[i][j]){
					++ans;
					bfs(i, j, b, m, n);
				}
		printf("%d\n", ans);
	}
	return 0;
}
