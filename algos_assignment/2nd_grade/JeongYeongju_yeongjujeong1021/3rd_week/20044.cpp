#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x, ans = 200000;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n * 2; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		ans = min(ans, v[i] + v[2 * n - 1 - i]);

	cout << ans << '\n';

	return 0;
}
