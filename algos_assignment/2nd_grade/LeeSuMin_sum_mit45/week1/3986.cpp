/////////////////////////////////////////////
//작성날짜: 2021.04.07
//문제: 백준 3986) 좋은 단어 
//기타: stack 사용 예제
/////////////////////////////////////////////


#include <stack>
#include <iostream>
using namespace std;

int main() {

	int num;
	int count = 0;
	cin >> num; //첫째 줄, 단어의 수

	for (int i = 0; i < num; i++) //반복문 사용
	{
		stack<char> stack; //stack 생성
		string input; //input 선언
		cin >> input; //반복문 사용해서 num만큼 입력받기
		int len = input.length(); //len 선언

		for (int j = 0; j < len; j++) {
			if (stack.size() != 0) { //size가 0이 아닐 경우
				if (stack.top() == input[j]) { 
					stack.pop(); //같다면 pop
				}
				else {
					stack.push(input[j]); //다르다면 push
				}
			}
			else { //size가 0일 경우
				stack.push(input[j]);
			}
		}

		if (stack.size() == 0) { // 짝이 다 맞아서 stack에 남은 게 없다면
			count=count+1;
		}
	}
	printf("%d", count);
}
