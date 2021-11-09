#include<iostream> 
#include<algorithm>
#include<string>

using namespace std;
int n,m,dp[1050][1050], ans=0;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			dp[i][j+1] = s[j] - 48;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] != 0) { //우측상단점을 고정으로 다른 점을 검사해서 최대값을 저장해 둠
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1; 
				ans = max(dp[i][j], ans);
			}
		}
	}
	cout << ans*ans;

	return 0;
}
