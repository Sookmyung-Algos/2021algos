#include <iostream>
#include <string>
#include <list>
using namespace std;
int main() {
	string editor;
	cin >> editor;
	list<char> L;
	for (auto c : editor) L.push_back(c);
	auto cusor = L.end();
	int q;
	cin >> q;
	while (q--) {
		char op;
		cin >> op;
		if (op == 'P') {
			char x;
			cin >> x;
			L.insert(cusor, x);
		}
		else if (op == 'L') {
			if (cusor != L.begin()) {
				cusor--;
			}
		}
		else if (op == 'D') {
			if (cusor != L.end()) {
				cusor++;
			}
		}
		else {//B
			if (cusor != L.begin()) {
				cusor=L.erase(--cusor);
			}

		}
			
	}
	for (auto c : L) cout << c;
}
