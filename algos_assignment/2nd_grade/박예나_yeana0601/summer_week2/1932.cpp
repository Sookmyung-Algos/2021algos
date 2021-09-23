#include <iostream>
#include <algorithm>
using namespace std;

int d[501][501] = { 0, };
int value[501][501] = { 0, };

int main()
{
	int Input = 0;
	cin >> Input;
	cin >> value[1][1];
	d[1][1] = value[1][1];


	for (int i = 2; i <= Input; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cin >> value[i][j];
			d[i][j] = value[i][j] + max(d[i - 1][j - 1], d[i - 1][j]);
		}
	}

	for (int i = 1; i <= Input; ++i)
		d[Input][0] = max(d[Input][0], d[Input][i]);
	
	cout << d[Input][0] << "\n";
	return 0;
}
