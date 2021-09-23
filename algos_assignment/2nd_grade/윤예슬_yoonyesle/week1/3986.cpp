#include <iostream>
#include <stack>
using namespace std;

bool balanced(char* s) {
	stack<char> st;
	while (*s) {
		if (st.empty())
			st.push(*s);
		else if (st.top() == *s)
			st.pop();
		else
			st.push(*s);
		++s;
	}
	return st.empty();
}

int main() {
	int n, ans = 0;
	char s[100001];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s);
		if (balanced(s))
			++ans;
	}
	printf("%d", ans);
	return 0;
}
