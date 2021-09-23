#include <iostream>
#include <algorithm>
using namespace std;
#define INF 10000000 //거쳐서 가면 비용 더 나올수있으므로 더 크게 초기화
int n, m;
int graph[101][101];
int a, b, c;
void floydWS() {
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				if (graph[a][k] + graph[k][b] < graph[a][b])
					graph[a][b] = graph[a][k] + graph[k][b];
			}
		}
	}
}
void printWS() {
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (graph[a][b] == INF) //a에서 b로 갈 수 없는 경우
				cout << 0 << " ";
			else
				cout << graph[a][b] << " ";
		}
		cout << "\n";
	}
}
int main() {
	cin >> n >> m;
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if(a != b) //자기자신으로 오는값(table에서 대각선)제외 초기화
				graph[a][b] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (graph[a][b] > c)
			graph[a][b] = c;
	}
	floydWS();
	printWS();
}
