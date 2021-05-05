#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <string> v;
vector <string> ans;

int main() {
	int n, m;
	string name;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> name;
		v.push_back(name);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		cin >> name;
		
		if (binary_search(v.begin(), v.end(), name)) {
			ans.push_back(name);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]<<'\n';
	}
}
