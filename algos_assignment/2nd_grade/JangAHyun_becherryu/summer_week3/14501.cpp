#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[16]; //기간
int p[16]; //보수
int dp[16];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];

	dp[0] = 0;

	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= i; j++)
			if (i - j >= t[j])
				dp[i] = max(dp[j] + p[j], dp[i]); //최대보수 구하기

	cout << dp[n + 1] << endl;

	return 0;
}
