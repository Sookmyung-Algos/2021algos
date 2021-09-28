#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n;
	vector <int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	cin >> k;
	k = n / k;
	for (auto it = v.begin(); it != v.end();) {
		sort(it, it + k);
		it += k;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	return 0;
}
