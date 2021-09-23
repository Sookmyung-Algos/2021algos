#include <iostream>
#include <algorithm>
using namespace std;

int before[1000001];
int dp[1000001];

int DP(int N)
{
	dp[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		// 3번 연산
		dp[i] = dp[i - 1] + 1;
		before[i] = i - 1;

		// 1번 연산
		if (i % 3 == 0)
		{
			if (dp[i] > dp[i / 3] + 1)
			{
				dp[i] = dp[i / 3] + 1;
				before[i] = i / 3;
			}
			
		}

		// 2번 연산
		if (i % 2 == 0)
		{
			if (dp[i] > dp[i / 2] + 1)
			{
				dp[i] = dp[i / 2] + 1;
				before[i] = i / 2;
			}
			
		}
	}

	return dp[N];
}

int main(void)
{
	int  X;
	cin >> X;

	cout << DP(X) << '\n';

	while (true)
	{
		cout << X << " ";
		X = before[X];
		if (X == 0)
      break;
	}

	return 0;
}
