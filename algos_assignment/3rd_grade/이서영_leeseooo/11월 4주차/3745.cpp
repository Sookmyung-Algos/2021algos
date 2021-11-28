#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (cin >> n) {
		vector<int>v;
		int cost;
		for (int i = 0; i < n; i++) {
			cin >> cost;
			if (v.empty() || v.back() < cost) {
				v.push_back(cost);
			}
			else {
				int idx = lower_bound(v.begin(), v.end(), cost) - v.begin();
				v[idx] = cost;
			}
		}
		cout << v.size() << '\n';
	}
}
