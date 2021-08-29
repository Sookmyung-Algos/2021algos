#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
long long n, m;
long long arr[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long low = 0;
	long long high = arr[0] * m;
	long long ans = arr[0] * m;
	while (high >= low) {
		long long sum = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < n; i++) {
			sum += mid / arr[i];
		}
		if (sum >= m) {
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << ans;
}
