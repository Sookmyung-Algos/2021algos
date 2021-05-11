#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, res;
	string name;
	vector<string> hear;
	vector<string> ans;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) { // 듣도 못한 사람 hear
		cin >> name;
		hear.push_back(name);
	}
	sort(hear.begin(), hear.end());
	for (int i = 0; i < m; i++) {
		cin >> name;
		res = binary_search(hear.begin(), hear.end(), name);
		if (res)
			ans.push_back(name);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

}
