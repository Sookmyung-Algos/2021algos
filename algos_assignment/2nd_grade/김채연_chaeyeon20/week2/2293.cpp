#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}
int dp[10001];
int main() {
	int n, k;
	int arr[101];
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	dp[0] = 1;
	for (int x = 1; x <= n; x++) {
		for (int y = arr[x]; y <= k; y++) {
			dp[y] = dp[y] + dp[y - arr[x]];
		}

	}
	cout << dp[k];
	return 0;
}
