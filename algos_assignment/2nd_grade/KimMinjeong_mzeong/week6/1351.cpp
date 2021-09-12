#include <iostream>
#include <map>
using namespace std;

long long n, p, q;
map<long long, long long> dp;

long long sol(long long x) {
	if (dp.find(x) != dp.end()) return dp[x];
	else return dp[x] = sol(x / p) + sol(x / q);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> p >> q;
	dp[0] = 1;
	cout << sol(n);
}
