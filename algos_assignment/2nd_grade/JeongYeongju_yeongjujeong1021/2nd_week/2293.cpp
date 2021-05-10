#include <iostream>
#include <iomanip>
using namespace std;

double dir[4]; // 각 방향의 확률 저장
int dx[4] = { 1, -1, 0, 0 }; // 동, 서
int dy[4] = { 0, 0, -1, 1 }; // 남, 북

double robot(int x, int y, int visit[30][30], int count, int n) {
	if (count == n)
		return 1;

	int visit_tmp[30][30];

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++)
			visit_tmp[i][j] = visit[i][j];
	}

	visit_tmp[x][y] = 1;

	double sum = 0;
	int xi, yi;
	for (int i = 0; i < 4; i++) {
		xi = x + dx[i];
		yi = y + dy[i];
		if (!visit_tmp[xi][yi])
			sum += dir[i] * robot(xi, yi, visit_tmp, count + 1, n);
	}

	return sum;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 4; i++) {
		cin >> dir[i];
		dir[i] /= 100;
	}

	int visit[30][30];

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++)
			visit[i][j] = 0;
	}

	cout << fixed << setprecision(9) << robot(n, n, visit, 0, n) << '\n';

	return 0;
}
