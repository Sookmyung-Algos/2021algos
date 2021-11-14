#include <iostream>
#include <vector>

using namespace std;

int n, k, l = 0, r=1, a;
vector<int> v(100050);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		r = r + a;
		v[i] = a;
	}
	while (l + 1 < r) { //이분탐색
		int count = 0, sum = 0;
		int mid = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			sum = sum + v[i];
			if (sum >= mid) { //그룹나누기
				sum = 0;
				count++;
			}
		}
		if (count >= k) {
			l = mid;
		}
		else {
			r = mid;
		}
	}

	cout << l;
	return 0;
}
