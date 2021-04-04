#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	int n, cnt = 0; //좋은 단어의 수 count
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> s; //stack 생성
		string w; //단어 입력받을 변수
		cin >> w;

		for (int j = 0; j < w.length(); j++) {//단어를 한 글자씩 검사
			if (s.size() == 0)	s.push(w[j]); //스택이 비었으므로 새 단어 push
			else {
				if (s.top() == w[j])	s.pop(); //스택의 top에 있는 글자가 현재 검사중인 글자와 같다면 pop
				else s.push(w[j]); //아니면 push
			}
		}
		if (s.empty())	cnt++; //검사 후 스택이 비어있으므로 좋은 단어
	}
	printf("%d\n", cnt);
	return 0;
}
