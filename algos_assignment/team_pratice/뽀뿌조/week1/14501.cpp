#include <iostream>
#include <algorithm>
using namespace std;
int n, res = 0;
int t[20], p[20];

void consult(int day, int pay) {
	if (day == n + 1)
		res = max(pay, res);
	if (day >= n + 1)
		return;
	consult(day + t[day], pay + p[day]); // 상담 할 경우
	consult(day + 1, pay); // 상담 안할 경우
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	consult(1, 0);
	cout << res;
}
