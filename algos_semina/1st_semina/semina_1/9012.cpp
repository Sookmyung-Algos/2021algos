#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;


int main() {

	int testcase;

	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		string s;
		bool check = false;
		 
		stack<int>paren;

		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				paren.push(s[i]);
			}
			else if (s[i] == ')') {
				if (paren.empty()) {
					cout << "NO\n";
					check = true;
					break;
				}
				else {
					paren.pop();
				}
				
			}
		}

		if (check) {
			continue;
		}

		if (paren.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}

}
