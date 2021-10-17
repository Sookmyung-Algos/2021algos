#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	string s; 
	char c;
	cin >> n;
	c = cin.get(); // 문자만 입력

	while (n--) {
		stack<int> st;
		int depth = 0;
		unsigned long long res = 1;
		getline(cin, s);

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') {
				st.push(0);
				depth = max(depth, (int)st.size());
			}
			else st.pop();
		}

		for (int i = 0; i < depth; i++) {
			res *= 2;
		}
		cout << res << '\n';
	}
}
