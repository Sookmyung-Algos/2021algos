#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	int cnt = 0;
	vector<int> v;
	cin >> s;
    
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i] - '0');
		cnt++;
	}
    
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < cnt; i++) {
		cout << v[i];
	}
	return 0;
}
