#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, c, ans;

int search(int l, int r, int ans) {
	if (l > r) return ans;

	int m = (l + r) / 2, cnt = 1, tmp = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] - v[tmp] >= m) {
			tmp = i;
			cnt++;
		}
	}
	if (cnt < c) return search(l, m - 1, ans);
	else return search(m + 1, r, max(m, ans));
}

int main() {
	int x;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	cout << search(1, v.back(), 0) << '\n';

	return 0;
}
