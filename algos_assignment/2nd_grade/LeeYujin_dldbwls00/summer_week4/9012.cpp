#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int t;
	cin >> t;

	
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		bool wrong = false;
		stack<char> st;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(')	st.push('(');
			else if (s[j] == '[')	st.push('[');
			else if (s[j] == ')' && (st.empty() || st.top() != '('))	wrong = true;
			else if (s[j] == ']' && (st.empty() || st.top() != '['))	wrong = true;
			else if (s[j] == ')') st.pop();
			else if (s[j] == ']') st.pop();
		}
		if (wrong || !st.empty())	cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
	return 0;
}
