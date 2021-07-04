#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	int n, m;

	cin >> t;

	while (t--)
	{
		int ans = 0;
		cin >> n >> m;

		vector<int> a(n);
		vector<int> b(m);

		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (int i = 0; i < n; i++)
		{
			auto cnt = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			ans += cnt;
		}

		cout << ans << endl;
	}
	return 0;
}
