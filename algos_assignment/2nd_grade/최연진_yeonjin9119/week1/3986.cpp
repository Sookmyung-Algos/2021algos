#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		stack<char> s;
		string tmp;
		cin >> tmp;
		int len = tmp.length();//tmp의 길이를 len 변수에 저장 -> for 문에 반복 횟수 지정

		for (int j = 0; j < len; j++) {
			if(s.size()!=0){//stack에 문자가 존재할 경우
				if (s.top() == tmp[j]) {//stack에 있는 문자 = 입력받은 문자=> pop으로 스택에서 삭제
					s.pop();}
				else {//스택에 가장 위에 있는 문자와 다르면 저장
					s.push(tmp[j]);
				}
			}
			else {//스택에 문자가 존재하지 않을 경우 (=첫 입력)
				s.push(tmp[j]);
			}
		}
		if (s.size() == 0) {// 모두 pop으로 스택에서 삭제되어 남아있는 문자가 존재하지 않음 == 올바른 문자
			cnt++;//문자의 개수 +1 해줌
		}
	}
	printf("%d", cnt);
}
