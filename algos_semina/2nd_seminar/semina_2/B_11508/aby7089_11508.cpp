#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
vector <int> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, total = 0, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		if ((i + 1) % 3 == 0)
			continue;
		else
			total += v[i];
	}
	cout << total;
}
