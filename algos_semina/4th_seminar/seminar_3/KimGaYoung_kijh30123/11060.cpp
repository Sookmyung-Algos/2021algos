#include<iostream> 

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	int dp[1050] = { 0, };
	dp[1] = 1;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int j = 1; j <= a; j++) {
			if (i + j > 1000) {
				break;
			}
			if (dp[i] == 0 && i != 1)
				continue;

			if (dp[i + j] > dp[i] + 1 || dp[i + j] == 0) {
				dp[i + j] = dp[i] + 1;
			}
		}
	}
	if (dp[n] == 0) {
		cout << -1;
	}
	else { 
		cout << dp[n]-1;
	}
	return 0;
}
