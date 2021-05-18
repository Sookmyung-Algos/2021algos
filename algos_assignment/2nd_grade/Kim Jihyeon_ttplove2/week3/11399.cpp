#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, p, pi, sum = 0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> p;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		pi = 0;
		for (int j = 0; j <= i; j++) {
			pi += v[j];
		}
		sum += pi;
	}
	cout << sum << "\n";
}
