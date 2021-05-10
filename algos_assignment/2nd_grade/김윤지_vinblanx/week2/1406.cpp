#include <iostream>
#include <list>

using namespace std;

int main() {
	string editor;
	cin >> editor; //편집기에 문자열 입력받기
	list<char> L; //리스트 L 선언
	int n;

	for (auto c : editor) { //입력받은 문자열을 c에 하나씩 할당하여
		L.push_back(c); //c를 리스트 L에 하나씩 넣어주기
	}
	auto cursor = L.end(); //문장의 맨 뒤에 커서를 위치시킴
	cin >> n; //명령어의 개수 받기

	while (n--) { //명령어를 처리하고 개수 감소시키면서 순회
		char op, add; //연산자와 문자 변수 선언
		cin >> op; //연산자 입력받기
		if (op == 'P'){ 
			cin >> add; //add라는 문자 받기
			L.insert(cursor, add); //받은 문자 add를 커서 왼쪽에 추가
		}

		else if (op == 'L') {
			if (cursor != L.begin()) //커서가 문장의 맨 앞이 아닐 때
				cursor--; //커서를 왼쪽으로 한 칸 옮김
		}

		else if (op == 'D') {
			if (cursor != L.end()) //커서가 문장의 맨 뒤가 아닐 때
				cursor++; //커서를 오른쪽으로 한 칸 옮김
		}

		else {
			if (cursor != L.begin()) //커서가 문장의 맨 앞이 아닐 때
				cursor = L.erase(--cursor); //커서 왼쪽에 있는 문자를 삭제함
		}
	}

	for (auto c : L) //리스트 L을 순회하며
		cout << c; //리스트의 원소를 모두 출력
}
