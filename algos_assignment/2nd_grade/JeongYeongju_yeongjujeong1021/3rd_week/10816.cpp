#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x, m;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	cin >> m;
	int* arr = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> x;
		arr[i] = upper_bound(v.begin(), v.end(), x)
			- lower_bound(v.begin(), v.end(), x);
	}

	for (int i = 0; i < m; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}
