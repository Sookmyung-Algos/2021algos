#include <iostream>
using namespace std;
int a, b, temp, cnt;
int a_coor[2], b_coor[2], c_coor[2];

void coor(int a, int b) {
	temp = 1;
	cnt = 0;
	while (a > 0) {
		a -= temp++;
		cnt++;
	}
	a_coor[1] = cnt + a;
	a_coor[0] = cnt + 1 - a_coor[1];
	temp = 1;
	cnt = 0;
	while (b > 0) {
		b -= temp++;
		cnt++;
	}
	b_coor[1] = cnt + b;
	b_coor[0] = cnt + 1 - b_coor[1];
}

int dot() {
	c_coor[0] = a_coor[0] + b_coor[0];
	c_coor[1] = a_coor[1] + b_coor[1];
	int Sum = 0;
	for (int i = 1; i <= c_coor[0] + c_coor[1] - 2; i++) {
		Sum += i;
	}
	return Sum+ c_coor[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		coor(a, b);
		cout << dot() << "\n";
	}
	return 0;
}
