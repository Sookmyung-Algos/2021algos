#include <iostream>
using namespace std;

int dp[1001][10] = {0, };

int n, ans = 0;
int mod = 10007;

int main() {
	cin>>n;

	for(int i = 0; i<10; i++){
		dp[1][i] = 1;
		//cout<<dp[0][i]<<" ";
	}

	for(int i = 2; i<=n; i++){
		dp[i][0] = 1;
		for(int j = 1; j<10; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			dp[i][j] = dp[i][j]%mod;
		}
	}
  
  //i자리 수이고, 맨 끝자리가 j일 때 
  //dp[1][j]은 전부 1 - 한자리수이므로
  //dp[i][0]은 전부 1 - 0, 00, 000 만 가능
  //dp[i][j]=dp[i-1][j] + dp[i][j-1]

	for(int k = 0; k<10; k++){
		ans += dp[n][k];
	}

	cout<<ans%mod;
}
