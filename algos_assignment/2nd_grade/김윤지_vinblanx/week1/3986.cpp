#include <iostream>
#include <stack> //스택을 사용해야 하므로 스택 헤더 파일 include

using namespace std;

int main(int argc, const char* argv[]) {
	int num, cnt = 0; //단어의 수, 좋은 단어의 수를 카운트 할 변수 선언
	cin >> num; //사용자로부터 단어의 수 입력 받기

	for (int i = 0; i < num; i++) { //입력받은 단어의 수만큼 단어를 반복해서 입력받기
		stack<char> word; // 문자형 stack 선언
		int wlen; //for문 조건에 필요한 '단어의 길이'를 저장할 변수 선언
		string w; //단어를 받을 변수 선언
		
		cin >> w; //단어 입력 받기
		wlen = w.length(); //length() 함수를 통해 wlen에 단어의 길이 저장
		
		for (int j = 0; j < wlen; j++) { //단어의 길이 동안 for문을 통해 한 글자씩 검사
			if (word.size() != 0) { //스택이 비어 있지 않을 때
				if (word.top() == w[j]) { //스택의 최상위 요소와 현재 글자가 같다면
					word.pop(); //짝을 이루므로 pop 해 줌.
				}
				else //스택의 최상위 요소와 현재 글자가 같지 않다면
					word.push(w[j]); //짝을 이루지 못했으므로 push 해 줌.
			}
			else //스택이 비어 있다면 짝을 이룰 글자가 없는 것이므로
				word.push(w[j]); //현재 글자를 스택에 저장
		}
		if (word.size() == 0) { //스택이 비어있다면
			cnt++; //좋은 단어이므로 카운트 증가
		}
	}
	cout << cnt << '\n'; //카운트 된 좋은 단어의 수 출력해주기
}
