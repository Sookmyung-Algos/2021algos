#include <iostream>
#include <stack>
#define MAX 500001
using namespace std;
int ans[MAX];

int main() {
	int n, k, i, q, cnt = 0, size;
	string str;
	cin >> n >> k >> str;
	stack<int> s;
	q = k;

	s.push(str[0] - '0');
	for (i = 1; i < n; i++) {
		while (q && !s.empty() && s.top() < str[i] - '0') {
			s.pop();
			q--;
		}
		s.push(str[i] - '0');
	}

	i = 0;
	size = s.size();
	while (s.size()) {
		ans[i++] = s.top();
		s.pop();
	}

	for (int i = size - 1; i > size - 1 - (n - k); i--)
		cout << ans[i];
	cout << '\n';

	return 0;
}
