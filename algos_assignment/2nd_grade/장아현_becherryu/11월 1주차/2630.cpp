#include <iostream>
using namespace std;

int n;
int paper[128][128];
int b, w;

void solve(int x, int y, int size) { //왼쪽 위 좌표, 한변의 길이
	int check = paper[x][y];
	for (int i = x; i < x + size; i++) { // check와 다른 색이 있는지 확인
		for (int j = y; j < y + size; j++) {
			if (check == 0 && paper[i][j] == 1) { // 다르면 check 변화
				check = 2;
			}
			else if (check == 1 && paper[i][j] == 0) {
				check = 2;
			}
			
			if (check == 2) { //check와 다른 색상이 존재
				solve(x, y, size / 2);
				solve(x, y + size / 2, size / 2);
				solve(x + size / 2, y, size / 2);
				solve(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}
	if (check == 0) // 색 카운트
		w++;
	else
		b++;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	solve(0, 0, n);
	cout << w << endl;
	cout << b << endl;

	return 0;
}
