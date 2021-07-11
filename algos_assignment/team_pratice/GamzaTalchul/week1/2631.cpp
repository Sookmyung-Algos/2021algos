//LIS 수열 사용

#include <iostream>
#include <vector>

#define MAX 201
using namespace std;

int n;
int v[MAX];
int dp[MAX];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int max = 0;
	dp[0] = 1;
	
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) {
			max = dp[i];
		}
	}

	cout << n - max;
}
