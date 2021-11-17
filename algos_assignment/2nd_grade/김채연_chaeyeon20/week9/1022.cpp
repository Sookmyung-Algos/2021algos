#include <iostream>

using namespace std;

// 북, 서, 남, 동
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int arr[50][5];

int main() {
	int r1, c1, r2, c2;

	cin >> r1 >> c1 >> r2 >> c2;

	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			arr[i][j] = 0;
		}
	}

	int x = 0, y = 0, dir = 3;
	int dcnt = 1, num = 1, cnt = 0;

	while (!((arr[0][0] != 0) && (arr[0][c2 - c1] != 0) && (arr[r2 - r1][0] != 0) && (arr[r2 - r1][c2 - c1] != 0))) {
		if (0 <= x - r1 && x - r1 <= (r2 - r1) && y - c1 >= 0 && y - c1 <= (c2 - c1)) {
			arr[x - r1][y - c1] = num;
		}

		++num;
		++cnt;

		x += dx[dir];
		y += dy[dir];

		if (cnt == dcnt) {
			cnt = 0;
			dir = (dir + 1) % 4;
			if (dir == 3 || dir == 1) {
				++dcnt;
			}
		}
	}

	cnt = 0;

	while (num) {
		num /= 10;
		++cnt; 
	}

	for (int i = 0; i <= (r2 - r1); i++) {
		for (int j = 0; j <= (c2 - c1); j++) {
			printf("%*d ", cnt, arr[i][j]);
		}
		cout << '\n';
	}

	return 0;
}
