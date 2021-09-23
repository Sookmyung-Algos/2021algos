#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int main() {
	int n, a;
	int count = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	for (int i = n - 2; i >= 0; i--) {
		while (v[i + 1] <= v[i]) {
			v[i]--;
			count++;
		}
	}
	cout << count;
}
