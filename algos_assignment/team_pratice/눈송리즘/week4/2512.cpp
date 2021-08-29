#include<iostream>
#include<algorithm>

using namespace std;

int n, m, arr[10001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;

	sort(arr, arr + n);

	int left = 0, right = arr[n - 1];
	long long res = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] >= mid)
				sum += mid;
			else
				sum += arr[i];
		}
		if (sum > m)
			right = mid - 1;
		else {
			left = mid + 1;
			res = max(res, mid);
		}
	}

	cout << res;
	return 0;
}
