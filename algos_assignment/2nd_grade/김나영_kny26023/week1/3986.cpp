#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> s;	//stack s 만들어주기
		string temp;	//cin으로 받을 변수 만들어주기
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			if (s.size() != 0) {	//s가 비어있지 않을 때
				if (s.top() == temp[j]) {	//s.top()이 temp[j]와 같을 때
					s.pop();	
				}
				else {	//s.top()이 temp[j]와 다를 때
					s.push(temp[j]);
				}
			}
			else {	//s가 비어있을 때
				s.push(temp[j]);
			}
		}
		if (s.size() == 0) {	//s.size()가 0이면 모두 짝이 지어졌다는 뜻
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
