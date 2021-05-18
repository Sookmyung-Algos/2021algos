#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int i, n, m, num;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (i = 0; i < m; i++) {
		int key;
		cin >> key;
		cout << upper_bound(v.begin(), v.end(), key) - lower_bound(v.begin(), v.end(), key) << " ";
	}
}
