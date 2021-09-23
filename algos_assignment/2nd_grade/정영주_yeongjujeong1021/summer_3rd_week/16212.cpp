#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0, a; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) cout << v[i] << ' ';
	cout << '\n';

	return 0;
}
