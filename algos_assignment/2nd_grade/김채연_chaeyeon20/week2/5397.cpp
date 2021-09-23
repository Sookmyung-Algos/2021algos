#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();
	
	int n;
	cin >> n;
	string str;
	

	while (n--) {
		cin >> str;
		list <char> li;
		for (auto c : str) li.push_back(c);
		list <char> result;
		auto cur = result.begin();
		for (auto i = li.begin(); i != li.end(); i++) {
			if (*i == '-') {
				if (cur == result.begin()) {
					continue;
					
				}
				cur = result.erase(--cur);
			
			}
			else if (*i == '<') {
				if (cur == result.begin()) continue;
				cur--;
			}
			else if (*i == '>') {
				if (cur == result.end()) continue;
				cur++;
			}
			else {
				result.insert(cur, *i);
			}
		}
		for (auto c : result) cout << c;
		cout << "\n";
	}
	
	return 0;
}
