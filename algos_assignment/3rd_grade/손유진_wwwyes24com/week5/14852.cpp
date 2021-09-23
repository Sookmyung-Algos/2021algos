#include <iostream>
using namespace std;
long long tile[1000010] = { 0, };
long long save[1000010];

int dp(int n) {
	for (int i = 3; i <= n; i++) {
		save[i] = (save[i - 1] + tile[i - 3]) % 1000000007;
		tile[i] = (tile[i - 1] * 2 + tile[i - 2] * 3 + save[i] * 2) % 1000000007;
	}
	return tile[n];
}

int main() {
	int n;
	cin >> n;
	tile[0] = 0, tile[1] = 2, tile[2] = 7;
	save[0] = 0, save[1] = 0, save[2] = 1;
	cout << dp(n);
}
