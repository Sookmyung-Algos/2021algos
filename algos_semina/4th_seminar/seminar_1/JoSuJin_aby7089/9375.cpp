#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int t, n, ans = 1;
string name, kinds;
map <string, int> m;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> name >> kinds;
			if (m.find(kinds) == m.end())
				m.insert({ kinds, 1 });
			else
				m[kinds]++;
		}
		for (auto k = m.begin(); k != m.end(); k++) {
			ans *= (k->second + 1);
		}
		cout << ans-1 << "\n";
		m.clear();
		ans = 1;
	}
}
