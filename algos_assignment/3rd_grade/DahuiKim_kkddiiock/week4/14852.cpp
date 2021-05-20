#include<iostream>
#define MAX 1000000007;
using namespace std;
long long int dp[1000001][2] = { 0, };
long long int dynamic(int n) {
	for (int i = 3; i <= n; i++) {
		dp[i][1] = (dp[i - 1][1] + dp[i - 3][0]) % MAX;
		dp[i][0] = (3 * dp[i - 2][0] + 2 * dp[i - 1][0] + 2 * dp[i][1])%MAX;
	}
	return dp[n][0];
}
int main() {
	int n;
	dp[0][0] = 0; dp[1][0] = 2; dp[2][0] = 7; dp[2][1] = 1;
	cin >> n;
	cout << dynamic(n) << endl;
	return 0;
}
