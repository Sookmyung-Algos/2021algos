#include <algorithm>
#include <iostream>
using namespace std;
int n, a[10000001], m, x;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (binary_search(a, a+n,x)) cout << "1 ";
		else cout << "0 ";
	}
}
