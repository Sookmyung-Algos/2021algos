#include<iostream>

using namespace std;

int n, m;
int weight[110][110] = { 0, };

void floyd() {
	//중간
	for (int i = 1; i <= n; i++) {
		//시작
		for (int t = 1; t <= n; t++) {
			//도착
			for (int j = 1; j <= n; j++) {
				// 시작 - 중간 && 중간 - 도착 으로 판단
				if (weight[t][i] == 1 && weight[i][j] == 1) {
					weight[t][j] = 1;
				}
				else if (weight[t][i] == -1 && weight[i][j] == -1) {
					weight[t][j] = -1;
				}

			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;

		weight[a][b] = 1;
		weight[b][a] = -1;
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			if (weight[i][j] == 0 && weight[j][i] == 0) {
				count++;
			}
		}
		cout << count << "\n";

	}

}
