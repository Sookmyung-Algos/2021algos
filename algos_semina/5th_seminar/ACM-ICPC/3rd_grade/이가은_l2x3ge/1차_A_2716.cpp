#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cin.get();
	for (int i = 0;i < n;i++) {
		int level = 0, stack = 0;
		string a;
		getline(cin, a);
		for (int k = 0;k < a.length();k++) {
			if (a[k] == '[') {
				stack++;
				level = max(level, stack);
			}
			else {
				stack--;
			}
		}
		int ans = 1;
		for (int k = 0;k < level;k++) {
			ans *= 2;
		}
		cout << ans << "\n";
	}

	return 0;
}
