#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	int n, m, size, x, cnt = 0;

	cin >> n >> m;

	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x % 10)
			v2.push_back(x);
		else v1.push_back(x);
	}

	sort(v1.begin(), v1.end());
	if (!v2.empty()) {
		sort(v2.begin(), v2.end());
		for (auto c : v2)
			v1.push_back(c);
	}

	for (int i = 0; i < n; i++) {
		while (m && v1[i] > 10) {
			v1[i] -= 10;
			cnt++;
			m--;
		}
		if (v1[i] == 10)
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
