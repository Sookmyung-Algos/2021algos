#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;

	int arr[100001];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int left = 0;
	int right = 0;
	int sum = arr[0];
	int ans = n + 1;

	while (left <= right && right < n) //부분합은 제 1항 ~ 제 n항 까지 순서대로의 합
	{
		if (sum < s)
			sum += arr[++right];
		else
		{
			ans = min(ans, right - left + 1);
			sum -= arr[left++];
		}
	}

	if (ans == n + 1)
		ans = 0;

	cout << ans << endl;

	return 0;
}
