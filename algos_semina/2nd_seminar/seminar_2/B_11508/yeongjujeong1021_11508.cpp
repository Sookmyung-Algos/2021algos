#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n, x, rmdr, sum = 0, cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	rmdr = n % 3;

	for (int i = 0; i < rmdr; i++) {
		sum += v[i];
	}

	for (int i = rmdr; i < n; i++) {
		if (cnt % 3 != 0)
			sum += v[i];
		cnt = (cnt + 1) % 3;
	}

	cout << sum << '\n';

	return 0;
}
