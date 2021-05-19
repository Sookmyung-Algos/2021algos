#include<iostream>
using namespace std;
int dp[1001] = { 0, };
int dynamic(int n) {
	dp[1] = 1;
	dp[2] = 2;
	if (dp[n] != 0)
		return dp[n];
	return dp[n] = (dynamic(n-1) + dynamic(n - 2))%10007;
}
int main() {
	int n,ans;
	cin >> n;
	ans=dynamic(n);
	cout << ans << endl;
}
