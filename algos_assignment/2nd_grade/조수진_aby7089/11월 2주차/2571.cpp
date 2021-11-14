#include <iostream>
#include <algorithm>
using namespace std;

int a[101][101], n, answer = 100;

int area_check(int nx, int ny, int mv) {  //가능한 넓이 찾기
	int min_depth = 100;
	for (int j = ny; j < ny + mv; j++) {  
		int depth = 0;
		for (int i = nx; i < 100; i++) {  
			if (a[i][j] == 0) break;  //검은색이 아닐때
			depth++;
		}
		min_depth = min(min_depth, depth);
	}
	return min_depth * mv;
}

int main() {
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				a[i][j]++;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (a[i][j] == 0) continue;
			for (int k = 0; k < 100; k++) {  //아래로 넓이 확인
				int ny = j + k;  
				if (ny >= 100) break;
				int area = area_check(i, j, k + 1);
				answer = max(answer, area);
			}
		}
	}
	cout << answer;
}
