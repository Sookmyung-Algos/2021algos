#include <iostream>
using namespace std;

int main()
{
	int n;
	int cnt = 0;

	cin >> n;

	for (int i = 666; ; i++)
	{
		int temp = i;
		while (temp >= 666) //연속된 666찾기
		{
			if (temp % 1000 == 666) 
			{
				cnt++; //시리즈 수
				break;
			}
			temp /= 10;
		}
		if (n == cnt)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}
