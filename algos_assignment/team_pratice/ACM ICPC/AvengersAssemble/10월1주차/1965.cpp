#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, ans = 1;
	int box[1001], dp[1001];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> box[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (box[j] < box[i] && dp[i] < dp[j] + 1) {
				//1~i-1 번째 중 i번째 상자의 크기보다 작고, 누적으로 넣은 상자의 수가 dp[i]보다 클 때
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
