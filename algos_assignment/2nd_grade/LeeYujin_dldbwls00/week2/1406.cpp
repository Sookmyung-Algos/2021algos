#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	string editor; // 초기에 주어지는 편집기 문자열
	cin >> editor;
	list<char> L; // 리스트에 넣어 관리

	for (auto c : editor) L.push_back(c); //뒤쪽으로 원소 삽입
	auto cursor = L.end(); //커서의 초기 위치
	int q; // 입력할 명령어의 개수
	cin >> q;
	
	while (q--) {
		char op; //명령어 입력
		cin >> op;
		if (op == 'P') {
			char ch;
			cin >> ch;
			L.insert(cursor, ch); // 입력받은 문자를 커서 왼쪽에 추가 
		}
		else if (op == 'L') { //커서를 왼쪽으로 한 칸
			if (cursor != L.begin())	cursor--;
		}
		else if (op == 'D') { //커서를 오른쪽으로 한 칸 
			if (cursor != L.end())	cursor++;
		}
		else { // op=='B'인 경우 커서 왼쪽에 있는 문자를 삭제
			if (cursor != L.begin())	cursor = L.erase(--cursor);
		}
	}
	//모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열
	for (auto c : L) cout << c; 

	return 0;
}
