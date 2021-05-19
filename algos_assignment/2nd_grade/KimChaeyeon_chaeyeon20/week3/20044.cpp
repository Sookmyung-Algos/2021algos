#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}


int main() {
	init();
	int n;
	cin >> n;
	vector <int> v;
	for (int i = 0; i <2*n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int min = 21e8;
	for (int i = 0; i < 2*n; i++) {
		int hap = v[i] + v[2*n - i -1];
		if (hap < min) {
			min = hap;
		}
	}
	cout << min;
	return 0;
}
