#include <iostream>
#include <list>
using namespace std;

int main() {
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
			char n;
			cin >> n;
			L.insert(cursor, n);
		}
		else if (op == 'L') {
			if (cursor != L.begin())
				cursor--;
		}
		else if (op == 'D') {
			if (cursor != L.end())
				cursor++;
		}
		else { // 'B'
			if (cursor != L.begin())
				L.erase((--cursor)++);
		}
	}
	for (auto c : L) cout << c;
	cout << '\n';

	return 0;
}
