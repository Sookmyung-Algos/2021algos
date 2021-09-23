#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		list<char> L;
		auto cursor = L.end();
		for (auto ch : str) {
			if (ch == '<') {
				if (cursor != L.begin())
					cursor--;
			}
			else if (ch == '>') {
				if (cursor != L.end())
					cursor++;
			}
			else if (ch == '-') {
				if (cursor != L.begin())
					L.erase((--cursor)++);
			}
			else { // operand
				L.insert(cursor, ch);
			}
		}
		for (auto c : L) cout << c;
		cout << '\n';
	}

	return 0;
}
