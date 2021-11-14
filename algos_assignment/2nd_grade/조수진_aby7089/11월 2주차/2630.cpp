#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, a[2200][2200];
int cnt[2];

bool chk(int x, int y, int n) {  //전체가 같은지 확인
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (a[i][j] != a[x][y])
				return false;
		}
	}
	return true;
}

void div(int x, int y, int n) {
	if (chk(x, y, n))
		cnt[a[x][y]]++; 
	else {  
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				div(x + n / 2 * i, y + n / 2 * j, n / 2);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];
	div(0, 0, N);
	cout << cnt[0] << "\n" << cnt[1] << "\n";
}
