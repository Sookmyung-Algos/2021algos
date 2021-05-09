#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void)
{
	string editor;
	cin >> editor;

	list<char> L;
	for (auto c : editor) L.push_back(c);
	auto cursor = L.end();

	int q;
	cin >> q;
	while (q--)
	{
		char op;
		cin >> op;
		if (op == 'P') {
			char w;
			cin >> w;
			L.insert(cursor, w);
		}
		else if (op == 'L') {
			if (cursor != L.begin())
				cursor--;
		}
		else if (op == 'D') {
			if (cursor != L.end())
				cursor++;
		}
		else if (op == 'B') {
			if (cursor != L.begin())
				cursor = L.erase(--cursor);
		}
	}
	for (auto c : L) cout << c;

	return 0;
}
