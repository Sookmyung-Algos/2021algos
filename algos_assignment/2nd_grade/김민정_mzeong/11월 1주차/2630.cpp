#include <iostream>
using namespace std;

int arr[128][128];
int b, w;

void solve(int x, int y, int size) {
	if (size == 1) {
		if (arr[x][y]) b++;
		else w++;
		return;
	}

	int check = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (check != arr[i][j]) {
				solve(x, y, size / 2);
				solve(x + size / 2, y, size / 2);
				solve(x, y + size / 2, size / 2);
				solve(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}
	if (check) b++;
	else w++;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0, n);
	cout << w << "\n" << b;
}
