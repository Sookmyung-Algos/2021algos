#include <iostream>
#include <vector>
using namespace std;

int main() {
   int n, m, dist[101][101] = {0};
   vector<int> v[101][101];
   scanf("%d%d", &n, &m);
   for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j) {
		v[i][j].push_back(i);
		v[i][j].push_back(j);
	}
   while (m--) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (!dist[a][b] || dist[a][b] > c) dist[a][b] = c;
   }
   for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
         for (int k = 1; k <= n; ++k) {
            //printf("%d %d %d, %d %d %d\n", i, j, k, dist[j][i], dist[i][k], dist[j][k]);
            if (!dist[j][i] || !dist[i][k]) continue;
            if (dist[j][k] &&dist[j][k] <= dist[j][i] + dist[i][k]) continue;
            dist[j][k] = dist[j][i] + dist[i][k];
            vector<int> t = v[i][k];
            v[j][k].clear();
            v[j][k] = v[j][i];
            for (int m = 1; m < t.size(); ++m)
            	v[j][k].push_back(t[m]);
         }
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j)
         if (i == j) printf("0 ");
         else printf("%d ", dist[i][j]);
      printf("\n");
   }
   for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j) {
		if (dist[i][j] == 0 || i == j) printf("0\n", i, j);
		else {
			printf("%d ", v[i][j].size());
			for (int k = 0; k < v[i][j].size(); ++k)
				printf("%d ", v[i][j][k]);
			printf("\n");
		}
	}
   return 0;
}
