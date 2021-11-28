#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int arr[1001];
int dp[1001] = { 0, };
int n;
int ans = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[i] < dp[j])
				{
					dp[i] = dp[j];
				}
			}
		}
		dp[i]++;
	}
	for (int i = 0; i < n; i++) {
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	cout << ans;
}
