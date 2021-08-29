#include <iostream>
#include <algorithm>
using namespace std;

int tk[100000];
int n, m;

bool sol(long long t) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += t / tk[i];
	}
	if (cnt >= m) return true;
	else return false;
}
int main() { 
	cin >> n >> m;

	long long mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> tk[i];
		if (tk[i] > mx) mx = tk[i];
	}

	long long s = 1, e = mx * m;
	long long ans = mx * m + 1;
	while (s <= e) {
		long long mid = (s + e) / 2;
		if (sol(mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else s = mid + 1;
	}
	cout << ans;
}
