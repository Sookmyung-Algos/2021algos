#include<iostream>

using namespace std;

int n, m;
int tall[510][510] = {0, };

void floyd() {

	//중간
	for (int i = 1; i <= n; i++) {
		//시작
		for (int t = 1; t <= n; t++) {
			//도착
			for (int j = 1; j <= n; j++) {
				// 시작 - 중간 && 중간 - 도착 으로 판단
				if (tall[t][i] == 1 && tall[i][j] == 1) {
					tall[t][j] = 1;
				}
				else if (tall[t][i] == -1 && tall[i][j] == -1) {
					tall[t][j] = -1;
				}

			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {

		int a, b;

		cin >> a >> b;

		tall[a][b] = 1;
		tall[b][a] = -1;

	}

	floyd();

	int check = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			if (tall[i][j] == 0 && tall[j][i] == 0) {
				check = 0;
				break;
			}
		}

		if (check) {
			count++;
		}
		check = 1;
	}

	cout << count;

}
