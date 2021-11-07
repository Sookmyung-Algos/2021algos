#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;
		v.push_back(card);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int key;
		cin >> key;
		cout << upper_bound(v.begin(), v.end(), key) - lower_bound(v.begin(), v.end(), key) << " ";
	}
}
