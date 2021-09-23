#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, x;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> x;

	sort(v.begin(), v.end());

	int start = 0, end = n - 1, sum, count = 0;

	while (1) {
		if (start >= end)
			break;

		sum = v[start] + v[end];

		if (sum == x) {
			start++;
			end--;
			count++;
		}
		else if (sum > x)
			end--;
		else
			start++;
	}
	cout << count << '\n';
}
