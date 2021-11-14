#include <bits/stdc++.h>
using namespace std;

bool board[101][101];
int n;
int answer = 100;

int area_check(int nx, int ny, int dir) {
	int min_depth = 100;
	for (int ii = ny; ii < ny + dir; ++ii) {
		int depth = 0;
		for (int i = nx; i < 100; ++i) {
			if (!board[i][ii])break;
			depth++;
		}
		min_depth = min(min_depth, depth);
	}
	return min_depth * dir;
}


void board_set(int nx, int ny) {
	for (int i = nx; i < nx + 10; ++i) {
		for (int ii = ny; ii < ny + 10; ++ii) {
			if (board[i][ii])continue;
			board[i][ii] = true;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int nx, ny;
	while (n--) {
		cin >> ny >> nx;
		board_set(nx, ny);
	}
    
	for (int i = 0; i < 100; ++i) {
		for (int ii = 0; ii < 100; ++ii) {
			if (!board[i][ii])continue;
			for (int dir = 0; dir < 100; ++dir) {
				int ny = ii + dir;
				if (ny >= 100)break;
				int area = area_check(i, ii, dir+1);
				answer = max(answer, area);
			}
		}
	}
	cout << answer;

	return 0;
}
