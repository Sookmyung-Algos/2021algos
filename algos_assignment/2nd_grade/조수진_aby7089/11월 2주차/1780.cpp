#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, a[2200][2200];
int cnt[3];

bool chk(int x, int y, int n) {  //전체가 같은지 확인
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
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
		cnt[a[x][y] + 1]++;//-1이 cnt[0]에, 0이 cnt[1]에 들어가도록 하기 위해 +1
	else {  
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				div(x + n / 3 * i, y + n / 3 * j, n / 3);
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
	cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2] << "\n";
}
