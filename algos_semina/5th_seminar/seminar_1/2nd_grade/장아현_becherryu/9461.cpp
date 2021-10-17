#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	long long P[101];

	while (t--)
	{
		cin >> n;
		memset(P, 0, sizeof(P));

		P[1] = 1;
		P[2] = 1;
		P[3] = 1;
		P[4] = 2;
		P[5] = 2; // 규칙이 없는 것(5)까지 정의

		for (int i = 6; i < n + 1; i++)
		{
			P[i] = P[i - 1] + P[i - 5];
		}
		cout << P[n] << endl;
	}
}
