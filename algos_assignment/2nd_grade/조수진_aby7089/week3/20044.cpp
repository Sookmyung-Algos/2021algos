#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector <int> v;
	vector <int> v2;
	int i, j;
	int n, w;
	cin >> n;
	for (int i = 0; i < 2*n; i++) {
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end());
	i = 0, j = (v.size() - 1);
	while (i < j) {
		v2.push_back(v[i++] + v[j--]);
	}
	sort(v2.begin(), v2.end());
	cout << v2[0];
}
