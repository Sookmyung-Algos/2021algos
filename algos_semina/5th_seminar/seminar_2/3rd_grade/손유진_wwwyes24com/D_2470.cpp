#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, left, right, min = 2000000000, ans1, ans2;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	left = 0;
	right = n - 1;
	
	while (left < right) {
		int sum = v[left] + v[right];
		if (min > abs(sum)) {
			min = abs(sum);
			ans1 = v[left];
			ans2 = v[right];

		}
		if (sum < 0)
			left++;
		else
			right--;
	}
	cout << ans1 << " " << ans2;
}
