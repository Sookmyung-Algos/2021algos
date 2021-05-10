#include<iostream>
#define INF 987654321
#define min(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

void floydWarshall();
int v[101][101];
int n, m;

int main() {
	cin >> n >> m;
	//초기화
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= n;j++) {
			if (i != j) {
				v[i][j] = INF;
			}
			else {
				v[i][j] = 0;
			}
		}
	}
	//입력
	for (int i = 0;i < m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b] = min(v[a][b], c);
	}
	
	//플로이드
	floydWarshall();
	
	//출력
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (v[i][j] == INF)
				v[i][j] = 0;
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

void floydWarshall() {
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
}
