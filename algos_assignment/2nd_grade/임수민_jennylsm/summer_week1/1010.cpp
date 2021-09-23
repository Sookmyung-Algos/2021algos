#include <iostream>
using namespace std;

int main() {
	int T, N, M, c;
	int arr[31][31] = { 0 };
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			arr[1][i] = i;
		}
		for (int i = 2; i <= N; i++) {
			for (int j = 2; j <= M; j++) {
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1]; //조합으로 결론 도출
			}
		}
		cout << arr[N][M] << endl;
	}
}
