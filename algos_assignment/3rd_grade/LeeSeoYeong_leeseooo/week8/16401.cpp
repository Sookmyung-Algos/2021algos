#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<memory.h>
using namespace std;
int m, n;
long long arr[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	long long _max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		_max = max(_max, arr[i]);
	}
	long long low = 0;
	long long high = _max;
	long long ans = 0;
	bool flag = false;
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] < mid)continue;
			if (mid == 0)break;
			cnt += arr[i] / mid;
		}
		if (cnt < m) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
			ans = max(ans, mid);
			flag = true;
		}
	}
	if (!flag) {
		cout << 0;
		return 0;
	}
	cout << ans;
}
