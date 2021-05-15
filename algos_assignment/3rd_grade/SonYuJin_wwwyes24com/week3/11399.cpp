#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, a, total = 0, ans;
	vector<pair<int, int>> p;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		p.push_back({ a, i });
	}
	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) 
			total += p[i].first;
	}
	cout << total << " ";
}
