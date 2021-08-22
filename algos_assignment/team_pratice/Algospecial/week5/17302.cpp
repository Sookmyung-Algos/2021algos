#include <iostream>
using namespace std;

int n, m, dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool even(int i, int j) {
	int cnt = 0;
	for (int k = 0; k < 4; ++k) {
		int next_i = i + dir[k][0], next_j = j + dir[k][1];
		if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
			continue;
		++cnt;
	}
	return !(cnt & 1);
}

bool odd(int i, int j) {
	int cnt = 0;
	for (int k = 0; k < 4; ++k) {
		int next_i = i + dir[k][0], next_j = j + dir[k][1];
		if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
			continue;
		++cnt;
	}
	return (cnt & 1);
}

char board[2002][2002];

bool is_white(int i, int j) {
	return board[i][j] == 'W';
}

bool is_black(int i, int j) {
	return board[i][j] == 'B';
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", board[i]);
	int ans[2002][2002];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			// 2번인 경우: 상하좌우 짝수 && W || 상하좌우 홀수 && B
			if (even(i, j) && is_white(i, j) || odd(i, j) && is_black(i, j))
				ans[i][j] = 2;
			// 3번인 경우: 상하좌우 홀수 && W || 상하좌우 짝수 && B
			else
				ans[i][j] = 3;
		}
	printf("1\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d", ans[i][j]);
		printf("\n");
	}
	return 0;
}
