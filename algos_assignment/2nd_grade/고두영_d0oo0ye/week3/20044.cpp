#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int i, n, w;
	int out = 200001;
	vector<int> v;

	cin >> n;

	for (i = 0; i < 2 * n; i++) {
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end());

	for (i = 0; i < 2 * n; i++)
		out = min(out, v[i] + v[2 * n - 1 - i]);

	cout << out;
}
