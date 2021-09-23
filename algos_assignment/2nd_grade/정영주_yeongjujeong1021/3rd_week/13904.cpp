#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int n, x, y, sum = 0, day = 0, 
		check[1001] = { 0, }, i, j;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(y, x));
	}

	for (auto i : v)
		day = max(day, i.second);
		
	sort(v.begin(), v.end(), greater<pair<int, int>>());

	for (i = 0; i < n; i++) {
		if (!day) break;
		if (check[v[i].second]) {
			for (j = v[i].second - 1; j > 0; j--) {
				if (!check[j]) {
					check[j] = 1;
					sum += v[i].first;
					day--;
					break;
				}
			}
		}
		else {
			check[v[i].second] = 1;
			sum += v[i].first;
			day--;
		}
	}
	cout << sum << '\n';

	return 0;
}
