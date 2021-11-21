#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, result, sum=0;
int dp[102][100002] = { 0, };//idx, cost dp는 최대메모리
int c[102], m[102];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		cin >> m[i];
	}
	for (int i = 1;i <= N;i++) {
		cin >> c[i];
		sum += c[i];
	}
	result = sum;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= sum;j++) {//cost
			if (j >= c[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
			else
				dp[i][j] = dp[i - 1][j];

			if (dp[i][j] >= M) result = min(result, j);
		}
	}

	cout << result << "\n";
	return 0;
}
