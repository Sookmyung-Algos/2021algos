#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) {
	string editor;
	cin >> editor;
	list<char> L;

	for (auto c : editor) L.push_back(c);
	auto cursor = L.end();
	int q;
	cin >> q;
	while (q--) {
		char op;
		cin >> op;
		if (op == 'P') {
			char s;
			cin >> s;
			L.insert(cursor, s);
		}
		else if (op == 'L') {
			if (cursor != L.begin()) cursor--;
		}
		else if (op == 'D') {
			if (cursor != L.end()) cursor++;
		}
		else { // 'B'
			if (cursor != L.begin()) {
				cursor--;
				//L.erase(cursor);
				cursor = L.erase(cursor);
			}
		}
	}
	for (auto c : L) cout << c;
}
