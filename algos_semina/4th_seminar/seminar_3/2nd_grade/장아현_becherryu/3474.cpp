//math - 10 = 2 * 5 이므로 2와 5의 배수(작은)를 모두 세면 0의 개수 파악가능
//2는 짝수이므로 5의 배수의 개수가 0의 개수
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		int fiv = 0;

		for (int j = 5; j <= n; j *= 5)
		{
			fiv += n / j;
		}
		cout << fiv << '\n'; //endl은 시간초과
	}
	return 0;
}
