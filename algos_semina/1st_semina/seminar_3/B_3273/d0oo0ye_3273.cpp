#include<iostream>
#include<algorithm>
using namespace std;

int n, x, ans;
int seq[100001];

int main()
{
	int left, right;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> seq[i];
	cin >> x;

	sort(seq, seq + n);
	left = 0;
	right = n - 1;

	while (left < right)
	{
		if (seq[left] + seq[right] == x)
		{
			ans++;
			right--;

		}
		else if (seq[left] + seq[right] > x)
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	cout << ans;
}
