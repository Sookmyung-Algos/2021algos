#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s, t;
	while (cin >> s >> t) {
		int j = 0;
		for (auto i: t) {
			if (s[j] == i)
				++j;
			if (j == s.length())
				break;
		}
		if (j == s.length())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
