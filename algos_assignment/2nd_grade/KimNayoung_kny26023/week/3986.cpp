#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> s;
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			if (s.size() != 0) {
				if (s.top() == temp[j]) {
					s.pop();
				}
				else {
					s.push(temp[j]);
				}
			}
			else {
				s.push(temp[j]);
			}
		}
		if (s.size() == 0) {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
