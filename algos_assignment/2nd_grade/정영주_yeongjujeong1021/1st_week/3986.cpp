#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	while (n--) {
		stack<char> s;
		string str;
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			if (s.size()) {
				if (s.top() == str[i]) s.pop();
				else s.push(str[i]);
			}
			else s.push(str[i]);
		}
		if (!s.size()) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
