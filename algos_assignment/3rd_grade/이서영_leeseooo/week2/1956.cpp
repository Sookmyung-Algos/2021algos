#include <iostream>
#include <algorithm>
using namespace std;
#define INF 100000000
int V, E;
int a, b, c;
int graph[401][401];
void floydWS() {
	for (int k = 1; k <= V; k++) {
		for (int a = 1; a <= V; a++) {
			for (int b = 1; b <= V; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}
}
int main() {
	cin >> V >> E;
	for (int a = 1; a <= V; a++) { //노드의 개수만큼 초기화
		for (int b = 1; b <= V; b++) {
			graph[a][b] = INF;
		}
	}
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	floydWS();
	int ans = 100000000;
	for (int i = 1; i <= V; i++) {
		//사이클이 생긴 경로->자기자신을 가리키는 위치에서 최소값찾기
		if (graph[i][i] < ans) ans = graph[i][i];
	}
	if (ans >= INF) cout << -1;
	else cout << ans << endl;
}
