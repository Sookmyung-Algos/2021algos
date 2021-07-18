#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> dp(n + 1, 0);
	dp[1] = 1;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[1] + dp[i - 1];
		for (int j = 2; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1); //최소 dp구하기(dp[제곱수] = 1이므로 1을 더해줌)
		}
	}
	cout << dp[n] << endl;

	return 0;
}
