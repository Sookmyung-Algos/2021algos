#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, a;
	int max_v = 0;
	int ans = 0;
	vector <int> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (max_v <= v[i]) {
			max_v = v[i];
			ans = max(ans, count);
			count = 0;

		}

		else
			count++;
	}
	ans = max(ans, count);

	cout << ans;


}
