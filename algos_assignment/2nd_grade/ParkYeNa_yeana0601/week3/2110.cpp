#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio;

	int n, c;
	vector <int>v;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	
	int first = v.front();
	int last = v.back();
	int ans = -1;

	while (first <= last) {
		int mid = (first+last) / 2;
		int past_idx = 0;
		int num = 1;

		for (int idx = 1; idx < n; idx++) {
			if (v.at(idx) - v.at(past_idx) >= mid) {
				past_idx = idx;
				num++;
			}
		}
		
		if (num >= c) first = mid + 1;
		else last = mid - 1;

		if (ans < mid && num >= c) ans = mid;
	}
	cout << ans;
	return 0;
}
