#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000
using namespace std;
int n, m, k;
int a[251][251];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int u, v, b, s, e;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				a[i][j] = 0; //길이 있는 경우 비용x
			else
				a[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> b;
		if (b == 1) { //양방향 연결 가능할 경우 양방향 cost를 0으로
			a[u][v] = 0; 
			a[v][u] = 0;
		}
		else { //일방인 경우 반대로 오는 길의 cost를 1로 해 몇 개를 바꿔야 하는지 알게 만듦
			a[u][v] = 0; 
			a[v][u] = 1;
		}
	}
	for (int p = 1; p <= n; p++) {  //플로이드 와샬
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][j], a[i][p] + a[p][j]);
			}
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> s >> e;
		cout << a[s][e] << "\n";
	}
}
