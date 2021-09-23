#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int search(int l, int r, int q) {
	if (l > r) return -1;
	int m = (l + r) / 2;
  
	if (v[m] < q) return search(m + 1, r, q);
	else if (v[m] > q) return search(l, m - 1, q);
	else return m; // v[m] == q
}

int main() {

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, x, m, s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	cin >> m;
	while (m--) {
		cin >> x;
		s = search(0, n - 1, x);
		if (s == -1)
			cout << '0' << '\n';
		else
			cout << '1' << '\n';
	}

	return 0;
}
