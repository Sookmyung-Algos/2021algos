#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <double> v;

int main() {
	int n;
	double a;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	double ans = v[0];

	for (int i = 1; i < n; i++) {
		if (v[i] * v[i - 1] > v[i]) {
			v[i] = v[i] * v[i - 1];
		}
		ans = max(ans, v[i]);
	}
	printf("%.3f", ans);
}
