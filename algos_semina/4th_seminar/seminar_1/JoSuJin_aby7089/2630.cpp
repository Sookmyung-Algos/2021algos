#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n, a[130][130], zero = 0, one = 0;

void divide(int x, int y, int N) {
	int cnt = 0;
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (a[i][j] == 1)  //따로 나눌 필요 없이 cnt로 0,1 확인
				cnt++;
		}
	}
	if (cnt == 0) //전체 0
		zero++;
	else if (cnt == N*N) //전체 1
		one++;
	else {  //그 외의 경우는 반씩 분할해서 다시 확인
		divide(x, y, N / 2);
		divide(x, y + N / 2, N / 2);
		divide(x + N / 2, y, N / 2);
		divide(x + N / 2, y + N / 2, N / 2);
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {  
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	divide(0, 0, n);
	cout << zero << "\n";
	cout << one << "\n";
}
