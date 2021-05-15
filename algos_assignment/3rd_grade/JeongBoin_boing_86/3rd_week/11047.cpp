#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int main() {
	int n, k, a;
	int count = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	for (int i = n - 1; i >= 0; i--) {
		count = k / v[i] + count;
		k = k % v[i];
	}
	
	cout << count;
}
