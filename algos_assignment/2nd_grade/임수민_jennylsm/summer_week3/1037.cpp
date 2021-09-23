#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[51], ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if (n == 1) ans = a[0] * a[0];
	else ans = a[0] * a[n - 1];
	cout << ans;
}
