#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N, r, c;
int ans;

void div(int x, int y, int n) {  
	if (y == r&&x == c) {
		cout << ans << "\n";
		return;
	}
	if (r < y + n && r >= y && c < x + n && c >= x) {  //해당 범위 안에 찾는 행열이 존재한다면
		div(x, y, n / 2);   //z순서로 탐색
		div(x + n / 2, y, n / 2);
		div(x, y + n / 2, n / 2);
		div(x + n / 2, y + n / 2, n / 2);
	}
	else
		ans += n*n;
}

int main() {
	cin >> N >> r >> c;
	div(0, 0, pow(2, N));
}
