//11404 플로이드
//MAX값 설정을 100,001로 해서 틀렸음. 

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 10000000
using namespace std;

int n, m;
int bus[101][101] = {0, }, Dp[101][101] = { 0, };

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (bus[a][b] == 0) bus[a][b] = c;
		else if (bus[a][b] > c) bus[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) Dp[i][j] = 0;
			else if (bus[i][j] == 0) Dp[i][j] = MAX;
			else Dp[i][j] = bus[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				Dp[i][j] = min(Dp[i][k] + Dp[k][j], Dp[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Dp[i][j] == MAX) cout << 0 << ' ';
			else cout << Dp[i][j] << ' ';
		}
		cout << endl;
	}
}
