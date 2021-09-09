#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t, n;
	vector <int> dp(11); 

	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		for (int i = 4; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		
		cout << dp[n] << endl;
	}

	return 0;
}
