#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int ans = 0, num = 5;
		int n; cin >> n;
		while (num <= n) {
			ans += n / num;
			num *= 5;
		}
		cout << ans << "\n";
	}
}
