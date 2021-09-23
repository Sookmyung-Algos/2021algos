#include <iostream>
using namespace std;
int dp[1500002] = { 0, };

void fibo() {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 0; i < 1500000; i++) {
		dp[i+2] = (dp[i+1] + dp[i]) % 1000000;
	}
}
int main(void) {
	long long n;
	cin >> n;
	fibo();
	cout << dp[n % 1500000];
	return 0;
}
