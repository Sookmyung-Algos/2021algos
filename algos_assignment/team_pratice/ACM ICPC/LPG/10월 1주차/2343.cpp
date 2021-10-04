#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n, m;
int arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l, r = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		r += arr[i];
	}
	l = *max_element(arr, arr + n);

	while (l <= r) {
		int mid = (l + r) / 2;

		int sum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (sum + arr[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += arr[i];
		}
		if (sum != 0) cnt++;

		if (cnt > m) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << l;
	return 0;
}
