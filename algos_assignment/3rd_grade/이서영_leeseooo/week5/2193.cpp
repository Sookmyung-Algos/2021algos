#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n;
long long dp[91]; // 범위때문에 long long 해줘야함
int main() {
	cin >> n;
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
}
