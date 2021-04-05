#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	string write; // 괄호문자들을 입력받음
	stack<char> s; 
	int cnt = 0; // 잘린 막대의 수를 세는 변수

	cin >> write;

	for (int i = 0; i < write.size(); i++) {
		if (write[i] == '(')	s.push(write[i]);// '('를 넣음 (막대의 수 세기)
		else { // ')'인 경우
			s.pop(); // 막대의 시작인 '('이 짝을 찾았으므로 pop
			if (write[i - 1] == '(')	cnt += s.size(); //이전 문자가 '('이면 ()이므로 레이저, 몇 개의 막대기가 겹쳐져 있는지 알 수 있음(스택)
			else cnt++; // 막대기의 끝을 만남
		}
	}
	cout << cnt;
	return 0;
}
