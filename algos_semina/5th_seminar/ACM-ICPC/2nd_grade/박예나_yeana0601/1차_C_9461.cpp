#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t;
long long p[101];
vector<int> v;
int temp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	p[0] = 1;
	p[1] = 1;
	p[2] = 1;
	p[3] = 2;
	p[4] = 2;
	for (int i = 0; i < t; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	int max_idx = max_element(v.begin(), v.end()) - v.begin();
	if (v[max_idx] > 4) {
		for (int j = 5; j <= v[max_idx]; j++) {
			p[j] = p[j - 1] + p[j - 5];
		}
	}
	for (int e : v) {
		cout << p[e-1] << "\n";
	}

}
