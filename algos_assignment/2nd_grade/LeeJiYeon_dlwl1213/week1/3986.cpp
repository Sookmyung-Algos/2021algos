#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include<string>
using namespace std;

int main() {
	int N; // 단어의 개수를 입력받기 위해 정수형 변수 N을 선언
	int count = 0; // 좋은단어의 개수를 셀 정수형 변수 count를 선언
	string word; // 단어는 word에 입력받게 됨

	cin >> N; // 단어 개수 N을 입력받음

	for (int i = 0; i < N; i++) {   // N개의 단어를 입력->좋은 단어인지 체크->count해주는 반복문 
		cin >> word;   //우선 판별할 단어를 입력받음 
		stack<int>s;    //A와 B의 쌍을 판별해주기 위해 s라는 이름의 stack생성
		
		for (int j = 0; j < word.length(); j++) {    //내부 for문은 stack에서 입력받은 word를 체크하기 위함
			if (s.empty()) {  // stack이 비어있다면 안에 비교할 내용이 없다는 것이므로 word의 원소 하나를 넣어줌
				s.push(word[j]);
			}
			else if (s.top() == word[j]) {    //stack의 top이 읽은 word의 원소와 같다면 쌍을 지어주기 위해 top을 빼줌
				s.pop();
			}
			else {    //stack의 top이 word의 원소와 다르다면 원소를 stack에 넣어줌
				s.push(word[j]); 
			}
		}
		if (s.empty())  //내부 for문을 통해 확인한 원소가 전부 쌍이 맞다면, 즉 좋은 단어라면 좋은단어의 개수인 count값을 증가함
			count++;
	}
	cout << count; //좋은 단어의 개수를 출력해주며 마무리

	return 0;
}
