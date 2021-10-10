#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int grid[51][51];
int ans=1;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m;j++) {
			grid[i][j] = tmp[j] - '0';
		}
	}
	int side = min(n, m);
	for (int i = 1; i < side; i++) {
		for (int x = 0; x+i < n; x++) {
			for (int y = 0; y+i < m; y++) {
				if (grid[x][y] == grid[x + i][y] && grid[x][y] == grid[x][y + i] && grid[x][y] == grid[x + i][y + i]) {
					if (i+1 > ans) {
						ans = i+1;
					}
				}
			}
		}
	}

	cout << ans*ans;
	return 0;
}
