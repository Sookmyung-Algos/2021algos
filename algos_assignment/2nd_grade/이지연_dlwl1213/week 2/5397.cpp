#include<iostream>
#include<list>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		list<char>ans;

		list<char>::iterator itr = ans.end();

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (itr == ans.begin())
					continue;
				itr--;
			}
			else if (str[i] == '>') {
				if (itr == ans.end())
					continue;
				itr++;
			}
			else if (str[i] == '-') {
				if (itr == ans.begin())
					continue;
				itr = ans.erase(--itr);
			}
			else {
				ans.insert(itr, str[i]);
			}
		}

		for (auto it = ans.begin(); it != ans.end(); it++)
			cout << *it;
		cout << '\n';
		ans.clear();
	}
	return 0;
}
