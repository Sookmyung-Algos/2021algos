#include <iostream>
#define MAX 1000000007
using namespace std;

long long fpow(int x) {
	if (x == 1) return 2;
	long long tmp = fpow(x / 2);
	if (x % 2) return ((tmp * tmp % MAX) * 2) % MAX;
	else return (tmp * tmp) % MAX;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t, n; cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1 || n == 2) cout << 1 << '\n';
		else cout << fpow(n - 2) << '\n';
	}

	return 0;
}
