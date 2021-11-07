#include <iostream>
#include <algorithm>
#include<string>
#include<stack>
#include<cmath>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		stack<char>st;
		string s;
		long long ans = 1;
		int h = 0;
		getline(cin, s);
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '[') {
				st.push(s[j]);
			}
			else if (s[j] == ']') {
				int size = st.size();
				h = max(h, size);//가장 큰 깊이
				st.pop();
			}
		}
		for (int j = 0; j < h; j++) {
			ans *= 2;
		}
		cout << ans << '\n';
	}
}
