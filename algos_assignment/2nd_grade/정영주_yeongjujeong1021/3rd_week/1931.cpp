#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b, q = 0, cnt = 1;
	vector<pair<int, int>> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++) {
		if (v[q].first <= v[i].second) {
			q = i;
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
