#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1'000'000'003

int dp[1001][1001][2];

bool last;

int solve(int cur, int left, bool pre) {
	if (!cur) {
		if (left) return 0;
		else if (pre != last) return 0;
		else return 1;
	}
	if ((cur + 1) / 2 < left)
		return 0;
	if (!left && last == false) return 1;
	if (dp[cur][left][pre] >= 0) return dp[cur][left][pre];
	int ret = 0;
	if (!pre && left)
		ret = solve(cur - 1, left - 1, true);
	ret = (ret + solve(cur - 1, left, false)) % MOD;
	return dp[cur][left][pre] = ret;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	memset(dp, -1, sizeof(dp));
	last = true; int ans = solve(n, k, last);
	memset(dp, -1, sizeof(dp));
	last = false; ans = (ans + solve(n, k, last)) % MOD;
	printf("%d", ans);
	return 0;
}
