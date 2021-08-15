#include <iostream>
using namespace std;
bool chk(int n)
{
	int fr, se, th;
	fr = n / 100;// 백
	se = (n / 10) % 10; //십
	th = n % 10; //일

	int mi1, mi2;
	mi1 = fr - se;
	mi2 = se - th;

	if (n < 100 || mi1 == mi2)
		return true;
	else
		return false;
}
int main()
{
	int n;
	
	cin >> n;

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (chk(i) == true)
			ans += 1;
	}
	cout << ans;

	return 0;
}
