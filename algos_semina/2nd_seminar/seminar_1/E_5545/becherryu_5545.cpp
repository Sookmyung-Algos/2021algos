#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, a, b;
	int c;
	
	cin >> n;
	cin >> a >> b;
	cin >> c;

	vector<int> d(n);

	for (int i = 0; i < n; i++)
		cin >> d[i];

	sort(d.rbegin(), d.rend()); //칼로리 내림차순정렬
	
	int totalcal = c;
	int totalprice = a;

	int calperone = c / a;
	for (int i = 0; i < n; i++)
	{
		totalprice += b;
		totalcal += d[i];
		if (calperone < totalcal / totalprice)
			calperone = totalcal / totalprice;
	}
	cout << calperone;

	return 0;

}
