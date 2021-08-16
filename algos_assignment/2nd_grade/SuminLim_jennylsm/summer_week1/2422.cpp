#include <vector>
#include <string>
#include <iostream>
using namespace std;

int n, m;
bool worst[201][201]; // 섞어먹으면 안되는 조합 선언

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		worst[a][b] = worst[b][a] = true;
	}
	int answer = 0; // 결론도출
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (worst[i][j]) continue;
			for (int k = j + 1; k <= n; k++) {
				if (worst[i][k] || worst[j][k]) continue;
				answer++;
			}
		}
	}
	cout << answer << endl;
}
