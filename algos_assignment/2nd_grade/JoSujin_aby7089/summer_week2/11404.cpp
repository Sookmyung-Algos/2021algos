#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int way[102][102];
int n, m;

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				way[j][k] = min(way[j][k], way[j][i] + way[i][k]);
			}
		}
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);	
	int a, b, c;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			way[i][j] = 123456789;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if(way[a][b]>c)  //기존보다 더 적은 비용인지 확인
			way[a][b] = c;
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || way[i][j] == 123456789)  //i에서 i로 가는 경우와 길이 없는 경우
				cout << "0" << " ";
			else
				cout << way[i][j] << " ";
		}
		cout << "\n";
	}
}
