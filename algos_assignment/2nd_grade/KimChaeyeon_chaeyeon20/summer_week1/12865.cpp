#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm> 
#include <queue>
#include <math.h>
#include <time.h>
#define MAX 100001
using namespace std;

int dp[101][100001];
int wei[101];
int val[101];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> wei[i] >> val[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - wei[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wei[i]] + val[i]);
			else dp[i][j] = dp[i - 1][j];

				
		}
	}
	cout << dp[n][k];

	return 0;
}
