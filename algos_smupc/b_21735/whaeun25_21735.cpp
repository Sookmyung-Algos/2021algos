#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int snow[101];
int snowball[101][11] = {0, };

int main() {
    ios::sync_with_stdio(false); 
    cout.tie(NULL); 
    cin.tie(NULL);

	int n, m, answer = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> snow[i];
	}

	snowball[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i < j || i / 2 + i % 2   >  j) {
				continue;
			}
			snowball[i][j] = max(snowball[i][j], snowball[i - 1][j - 1] + snow[i]);
			if (i+2 <= n) {
				snowball[i + 2][j + 1] = snowball[i][j] / 2 + snow[i + 2];
			}
			answer = max(snowball[i][j], answer);
		}
	}
	cout << answer;
}
