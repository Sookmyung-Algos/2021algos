#include<iostream>

using namespace std;

int n, k, s;

int history[410][410];

void floyd() {

	//중간
	for (int i = 1; i <= n; i++) {
		//시작
		for (int t = 1; t <= n; t++) {
			//도착
			for (int j = 1; j <= n; j++) {
				// 시작 - 중간 && 중간 - 도착 으로 판단
				if (history[t][i] == 1 && history[i][j] == 1) {
					history[t][j] = 1;
				}
				else if (history[t][i] == -1 && history[i][j] == -1) {
					history[t][j] = -1;
				}
				
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;

		cin >> a >> b;

		history[a][b] = -1;
		history[b][a] = 1;
	}

	floyd();

	cin >> s;

	for (int i = 0; i < s; i++) {
		int a, b;

		cin >> a >> b;
		cout << history[a][b] << "\n";
	}

}
