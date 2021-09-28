#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maze[1001];
int dp[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> maze[i];
		dp[i] = 1000000;
	}
	
	dp[1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= i + maze[i] && j <= n; j++)
		{
			dp[j] = min(dp[j], dp[i] + 1);
		}
	}
	
	if (dp[n] == 1000000)
		cout << -1 << '\n';
	else
		cout << dp[n] << '\n';

	return 0;
}
