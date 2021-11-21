#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int ch[MAX][MAX];
int n, m, a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ch[a][b] = 1; 
	}

	for (int student = 1; student <= n; student++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (ch[i][student] && ch[student][j]) {
					ch[i][j] = 1;
				}
			}
		}
	}
	int res = 0;
	for (int student = 1; student <= n; student++) {
		int bigger = 0; int smaller = 0;
		for (int i = 1; i <= n; i++) {
			if (student == i) continue;
			if (ch[i][student]) bigger++;
			if (ch[student][i]) smaller++;
		}
		if (bigger + smaller == n - 1) res++;
	}
	cout << res;
	return 0;
}
