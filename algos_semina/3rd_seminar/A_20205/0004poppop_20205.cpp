#include <iostream>

using namespace std;

int map[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K, tmp;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			for (int x = i * K; x < i * K + K; x++) {
				for (int y = j * K; y < j * K + K; y++) {
					map[x][y] = tmp;
				}
			}
		}
	}

	for (int i = 0; i < N * K; i++) {
		for (int j = 0; j < N * K; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
