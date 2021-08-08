#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int pixel[11][11];
	int up[101][101];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> pixel[i][j];
	}
	int c = 0;
	for (int i = 0; i < n*k; i++) {
		int b = 0;
		for (int j = 0; j < n*k; j++) {
			up[i][j] = pixel[c][b];
			if ((j + 1) % k == 0) //
				b++;
		}
		if ((i + 1) % k == 0)
			c++;
	}
	for (int i = 0; i < n*k; i++) {
		for (int j = 0; j < n*k; j++)
			cout << up[i][j] << ' ';
		cout << "\n";
	}
}
