#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, input[1001], dp[1001] = { 0, };
	cin >> num;
	for (int i = 1;i < num + 1;i++) {
		cin >> input[i];
	}
	for (int i = 1;i < num + 1;i++) {
		for (int j = 1;j < i;j++) {
			if (input[i] > input[j]) {
				if (dp[i] < dp[j]) {
					dp[i] = dp[j];
				}
			}
		}
		dp[i]++;
	}
	int Max = 0;
	for (int i = 1;i < num + 1;i++) {
		if (dp[i] > Max) {
			Max = dp[i];
		}
	}

	cout << Max;

	return 0;
}
