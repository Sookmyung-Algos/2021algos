#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#include<memory.h>
#include<stack>
#include<cstdlib>
#include<climits>
using namespace std;
int main() {
	int n;
	cin >> n;
	int dp[1001];
	dp[1] = 1; dp[2] = 3; dp[3] = 5;
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;//1,3,5,11...점화식
	}
	cout << dp[n];
}
