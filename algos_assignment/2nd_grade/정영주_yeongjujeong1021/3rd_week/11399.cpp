#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x, tmp = 0, sum = 0;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		tmp += v[i];
		sum += tmp;
	}

	cout << sum << '\n';

	return 0;
}
