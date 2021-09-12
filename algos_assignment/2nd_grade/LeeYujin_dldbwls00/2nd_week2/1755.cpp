#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string num[10] = { "zero", "one", "two", "three", "four", "five", "siz", "seven", "eight", "nine" };
int main() {
	int m, n;
	cin >> m >> n;
	
	vector<pair<string, int>> v;
	string s;
	for (int i = m; i <= n; i++) {
		if (i < 10) {
			s = num[i % 10];
			v.push_back({ s,i });
		}
		else {
			s = num[i / 10] + " " + num[i % 10];
			v.push_back({ s,i });
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " ";
		if (i % 10 == 9)	cout << '\n';
	}

	return 0;
}
