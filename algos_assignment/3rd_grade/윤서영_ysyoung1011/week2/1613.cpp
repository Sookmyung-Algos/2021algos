//1613 역사
#include <iostream>
using namespace std;

int n, k, s;
int num[401][401] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i<k; i++) {
		int a, b;
		cin >> a >> b ;
		num[a][b] = -1;
		num[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (num[i][k] == -1 && num[k][j] == -1)
					num[i][j] = -1;
				else if (num[i][k] == 1 && num[k][j] == 1)
					num[i][j] = 1;
			}
		}
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		cout << num[a][b] << '\n';
	}
}
