#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	int n, m;
	string name;
	cin >> n >> m;
	set<string> s1, s2;
	for (int i = 0; i < n; i++) {
		cin >> name;
		s1.insert(name);
	}
	for (int i = 0; i < m; i++) {
		cin >> name;
		if (s1.find(name) != s1.end())
			s2.insert(name);
	}
	cout << s2.size() << "\n";
	set<string>::iterator it;
	for (auto &k : s2)
		cout << k << "\n";
	return 0;
}
