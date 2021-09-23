#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack <int> s;  //함수를 적용할 stack s를 생성해줌
	int N;  //명령의 수를 입력받기 위한 정수형 변수 N을 선언
	cin >> N;  //N을 입력받음

	for (int i = 0; i < N; i++) {  //입력받은 명령의 수만큼 반복하는 for문
		string str;  //명령은 string의 형식으로 입력받게 됨
		cin >> str;  //str에 명령을 입력받음
		if (str == "push") {  //명령이 push이면
			int a;  
			cin >> a;  //pusg해줄 정수 a를 입력받고
			s.push(a);  //stack에 push해줌
		}
		else if (str == "top") {  //명령이 top이면
			if (s.empty())   //우선 stack이 비어있는지 확인
				cout << "-1" << "\n";  //비어있다면 -1출력
			else  //stack에 원소가 있다면
				cout << s.top() << "\n";  //top을 출력
		}
		else if (str == "pop") {  //명령이 pop이라면
			if (s.empty())   //stack이 비어있는지 확인해서
				cout << "-1" << "\n";  //비어있으면 -1출력
			else {   //비어있지 않으면 top의 원소를 출력한 후 pop해줌
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (str == "empty") {  //명령이 empty이면
			cout << s.empty() << "\n";  //empty함수를 통해 0,1의 값을 출력
		}
		else {  //마지막으로 명령이 size이면
			cout << s.size() << "\n";  //스택에 들어있는 정수의 개수를 출력
		}  
	}
	return 0;
}
