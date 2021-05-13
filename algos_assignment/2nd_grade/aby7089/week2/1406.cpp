#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	string s;
	char q,m;
	int n;
	cin >> s;
	cin >> n;
	list <char> l;
	for (auto c : s)
		l.push_back(c);
	auto cursor = l.end();
	while(n--) {
		cin >> q;
		if (q == 'L') {
			if (cursor != l.begin())
				cursor--;
		}
		else if (q == 'D') {
			if (cursor != l.end())
				cursor++;
		}
		else if (q == 'P') {
			cin >> m;
			l.insert(cursor, m);
		}
		else {
			if (cursor != l.begin())
				cursor=l.erase(--cursor);
		}
	}
	for(auto c:l)
		cout << c;
}
