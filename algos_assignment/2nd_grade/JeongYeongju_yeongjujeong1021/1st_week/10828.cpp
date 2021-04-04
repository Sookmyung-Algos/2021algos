// 과제가 4문제밖에 없어서 스택 예제 (백준 10838번 https://www.acmicpc.net/problem/10828) 풀었습니다.

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int n, num;
	cin >> n;
	stack<int> s;
	char str[6];
	while (n--) {
		cin >> str;
		if (!strcmp(str, "push")) {
			cin >> num; s.push(num);
		}
		else if (!strcmp(str, "pop")) {
			if (s.size()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else cout << -1 << '\n';
		}
		else if (!strcmp(str, "size"))
			cout << s.size() << '\n';
		else if (!strcmp(str, "empty"))
			cout << (s.size() ? 0 : 1) << '\n';
		else if (!strcmp(str, "top"))
			cout << (s.size() ? s.top() : -1) << '\n';
	}

	return 0;
}
