#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, i;
	cin >> n >> m;

	vector<string> s;
	vector<string> k;
	char c[1][20];

	for (i = 0; i < n; i++)
	{
		cin >> c[0];
		s.push_back(c[0]);
	}
	for (i=0; i<m; i++)
	{
		cin >> c[0];
		s.push_back(c[0]);
	}
	sort(s.begin(), s.end());

	for (i = 0; i < n + m; i++)
	{
		if (s[i] == s[i + 1]) {
			k.push_back(s[i]);
			i++;
		}
	}
  
	cout << k.size() << "\n";
	sort(k.begin(), k.end());
	
	for (i = 0; i < k.size(); i++)
		cout << k[i] << "\n";
	return 0;
}
