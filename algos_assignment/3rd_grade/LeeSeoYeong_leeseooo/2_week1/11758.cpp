#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct pos {
	int x;
	int y;
}p[3];
int CCW(pos A, pos B, pos C) {
	// (AB벡터) - (AC벡터)
    // 외적에 의해 z축이 양수면 반시계, 음수면 시계
	return (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		p[i].x = a; p[i].y = b;
	}
	if (CCW(p[0], p[1], p[2]) > 0)cout << 1;
	else if (CCW(p[0], p[1], p[2]) < 0)cout << -1;
	else cout << 0;
}
