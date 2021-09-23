#include<iostream>
#include<string>
#include<list>
#include<algorithm> //라이브러리 불러오기
using namespace std;

int main(void) {

	string editor;
	cin >> editor;
	list<char> L;
	char c;

	for (auto c : editor) L.push_back(c);
	auto cursor = L.end();
	int q;
	cin >> q;

	while (q--) {
		char op;
		cin >> op;
		if (op == 'P') {
			cin >> c;
			L.insert(cursor, c); //넣어야 할 문자를 받고 넣기 
		}
		else if (op == 'L') {
			if (cursor != L.begin()) { //커서가 맨 앞이면 무시
				cursor--; //왼쪽으로 옮김
			}
		}
		else if (op == 'D') { 
			if (cursor != L.end()) { //커서가 맨 뒤면 무시
				cursor++; //오른쪽으로 옮김
			}
		}
		else {
			if (cursor != L.begin()) { //커서가 맨 앞이면 무시
				cursor--;
				cursor=L.erase(cursor); //erase는 cursor의 주소를 반환하므로 저장해두어야 한다.
				//저장하지 않으면 런타임에러가 나온다.
			}
		}
	}
	for (auto c : L) cout << c;

	return 0;
}
