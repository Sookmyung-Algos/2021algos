#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n,k;
	cin >> n >> k;

	int left = 1, right = k;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}

		if (cnt < k)
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << left;
}
