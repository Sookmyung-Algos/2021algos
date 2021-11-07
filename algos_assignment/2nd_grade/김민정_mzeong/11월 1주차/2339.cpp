#include <iostream>
using namespace std;

int a[20][20];

int slice(int x1, int y1, int x2, int y2, bool isHorizontal) {
	int impurity = 0, jewel = 0;
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (a[i][j] == 1) impurity++;
			else if (a[i][j] == 2) jewel++;
		}
	}
	if (jewel == 0) return 0;
	else if (jewel == 1 && impurity == 0) return 1;
	else {
		int result = 0;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				if (a[i][j] == 1) {
					if (isHorizontal) {
						bool hasJewel = false;
						for (int k = x1; k < x2 && !hasJewel; k++) {
							if (a[k][j] == 2) hasJewel = true;
						}
						if (!hasJewel) result += slice(x1, y1, x2, j, false) * slice(x1, j + 1, x2, y2, false);
					}
					else {
						bool hasJewel = false;
						for (int k = y1; k < y2 && !hasJewel; k++) {
							if (a[i][k] == 2) hasJewel = true;
						}
						if (!hasJewel) result += slice(x1, y1, i, y2, true) * slice(i + 1, y1, x2, y2, true);
					}
				}
			}
		}
		return result;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = slice(0, 0, n, n, true) + slice(0, 0, n, n, false);
	cout << (ans > 0 ? ans : -1);
}
