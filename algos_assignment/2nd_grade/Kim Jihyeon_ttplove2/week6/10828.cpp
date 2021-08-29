#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> s;

void s_push(int x)
{
	s.push(x);
}

int s_pop()
{
	if (!s.empty()) {
		int t = s.top();
		s.pop();
		return t;
	}
	return -1;
}

int s_size()
{
	return s.size();
}

int isempty()
{
	return s.empty();
}

int s_top()
{
	if (!s.empty()) {
		int t = s.top();
		return t;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; int x; int ans;
		cin >> s;

		if (s == "push") {
			cin >> x;
			s_push(x);
		}
		else if (s == "pop") {
			cout << s_pop() << "\n";
		}
		else if (s == "size") {
			cout << s_size() << "\n";
		}
		else if (s == "empty") {
			cout << isempty() << "\n";
		}
		else { // top인 경우
			cout << s_top() << "\n";
		}
	}
}
