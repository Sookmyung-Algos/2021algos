#include <iostream>
using namespace std;
int main(){
	int dp[1001] = { 0, };
	int n,tmp,ans;
	cin >> n;
	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (dp[i] == 0)	break;
		for (int j = 1; j <= tmp; j++) {
			if (i + j > 1000) break;
			if (dp[i + j] > dp[i] + 1 || dp[i + j] == 0) {
				dp[i + j] = dp[i] + 1;
			}
		}
	}
	ans = (dp[n] == 0) ? -1 : dp[n] - 1;
	cout << ans << '\n';
	return 0;
}
