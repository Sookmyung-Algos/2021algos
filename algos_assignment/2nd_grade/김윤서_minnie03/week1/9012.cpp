#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<string>result;

int main() {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		stack<char>vps;
		char s[50];
		scanf("%s", s);

		int j = 0;
		while (1) {
			if (s[j] == '(') {
				vps.push('(');
			}
			else if (s[j] == ')') {
				if (vps.empty())
					vps.push(')');
				else {
					if (vps.top() == '(') {
						vps.pop();
					}
					else
						break;
				}
			}
			else
				break;
			j++;
		}

		if (vps.empty()) {
			result.push("YES");
		}
		else {
			result.push("NO");
		}
	}

	char prt;

	for (int i = 1; i <= t; i++) {
		cout << result.front() <<'\n';
		result.pop();
	}

	return 0;
}
