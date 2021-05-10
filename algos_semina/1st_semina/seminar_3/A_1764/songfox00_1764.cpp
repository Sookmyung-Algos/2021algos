#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, int> ma;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		ma.insert({ str, 0 });
	}

	for (int i = 0; i < m; i++) {
		cin >> str;
		if (ma.find(str) != ma.end()) {
			ma[str]++;
		}
		else
			ma.insert({ str,0 });
	}

	vector<string>res;
	for (auto it = ma.begin(); it != ma.end(); it++) {
		if (it->second != 0) {
			res.push_back(it->first);
		}
	}

	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}
}
