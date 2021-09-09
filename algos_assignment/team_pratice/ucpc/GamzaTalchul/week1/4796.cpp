//그리디
#include<iostream>
using namespace std;

int main()

{
	int l, p, v, ans, cnt=1;

	while (1)
	{
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;
		else
		{
			if (p < v)
			{
				int one, two;
				one = v / p*l;
				two = v%p > l ? l : v%p;
				ans = one + two;
				cout << "Case "<<cnt++<<": " << ans << "\n";
			}
		}
	}
	return 0;
}
