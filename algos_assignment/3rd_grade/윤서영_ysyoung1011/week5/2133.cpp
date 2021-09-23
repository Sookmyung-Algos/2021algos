#include <iostream>
using namespace std;

int dp[31] = {0, };

int f(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (dp[x] != 0) return dp[x];
	int result = f(x-2) * 3;
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0)
			result += f(x-i) * 2;
	}
	dp[x] = result;
	return dp[x];
}

int main() {
	int n;
	cin >> n;
	cout << f(n);
}
