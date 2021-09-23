#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	int n;
	int s = 0;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());
	
	for (int i = 0; i < n; i++)
		s += a[i] * b[i];

	cout << s << endl;

	return 0;
}
