#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		int coin[21], dp[100001] = { 0, };
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> coin[i];
		cin >> m;
		dp[0] = 1;
		for (int i = 1; i <= n; i++) { 
			for (int j = coin[i]; j <= m; j++) {
				//j원을 coin[i]로 만들 수 있는 경우의 수를 누적해 저장
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[m] << '\n';
	}
}
