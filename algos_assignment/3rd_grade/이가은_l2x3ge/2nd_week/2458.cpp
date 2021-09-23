#include<iostream>
#define INF 55555
using namespace std;

int v[501][501] = { 0, };
int n, m;
void floydwarshall();

//INF: 모름
//앞이 더 작으면 1, 뒤가 더 작으면 -1

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	//초기화
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			v[i][j] = INF;
			if (i == j) {
				v[i][j] = 0;
			}
		}
	}
	//입력
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		v[b][a] = -1;
		v[a][b] = 1;
	}
	floydwarshall();
	//출력
	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (v[i][j] == INF)
				break;
			else if (j == n)
				cnt++;
		}
	}
	cout << cnt;
}

void floydwarshall() {
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (v[i][k] == 1 && v[k][j] == 1)
					v[i][j] = 1;
				else if (v[i][k] == -1 && v[k][j] == -1)
					v[i][j] = -1;
			}
		}
	}
}
