#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, budget, sum;

int search(int l, int r, int ans) {
	if (l > r) return ans;
	int m = (l + r) / 2;
	sum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] <= m)
			sum += v[i];
		else sum += m;
	}
	if (sum > budget) return search(l, m - 1, ans);
	else return search(m + 1, r, m);
}

int main() {
	int x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	cin >> budget;

	cout << search(0, v.back(), 0) << '\n';

	return 0;
}
