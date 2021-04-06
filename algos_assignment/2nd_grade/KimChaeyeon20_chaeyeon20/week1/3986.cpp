#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int isGoodword(string s) {

	stack <char> st;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (st.empty()) st.push(s[i]);
		else {
			if (st.top() != s[i]) st.push(s[i]);
			else st.pop();
		}
	}
	if (st.size() == 0) return 1;
	return 0;
}

int main() {
	init();
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s.size() % 2 == 1) continue;
		
		cnt += isGoodword(s);
		
	}
	cout << cnt;
	return 0;
}
