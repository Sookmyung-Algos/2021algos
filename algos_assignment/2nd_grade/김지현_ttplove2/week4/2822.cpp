#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, sum = 0;
	vector<pair<int, int>> v(8);
	vector<int> top;
	for (int i = 0; i < 8; i++) {
		cin >> n;
		v.push_back(make_pair(n, i + 1));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	for (int i = 0; i < 5; i++) {
		sum += v[i].first;
		top.push_back(v[i].second);
	}
	cout << sum << "\n";
	sort(top.begin(), top.end());
	for (int i = 0; i < 5; i++) {
		cout << top[i] << " ";
	}
	return 0;
}
