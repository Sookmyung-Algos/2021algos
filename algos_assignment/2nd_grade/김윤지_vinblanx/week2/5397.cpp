#include <iostream>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--) {
		string password;
		cin >> password; //문자열 입력받기

		list<char> pw; //리스트 pw 선언
		
		auto cursor = pw.end(); //문장의 맨 뒤에 커서를 위치시킴

		for (auto c : password) { //입력받은 문자열을 c에 하나씩 할당하여

			if (c == '<') {
				if (cursor != pw.begin()) //커서가 문장의 맨 앞이 아닐 때
					cursor--; //커서를 왼쪽으로 한 칸 옮김
			}

			else if (c == '>') {
				if (cursor != pw.end()) //커서가 문장의 맨 뒤가 아닐 때
					cursor++; //커서를 오른쪽으로 한 칸 옮김
			}

			else if (c == '-') {
				if (cursor != pw.begin()) //커서가 문장의 맨 앞이 아닐 때
					cursor = pw.erase(--cursor); //커서 바로 앞의 문자를 삭제함
			}

			else {
				pw.insert(cursor, c); //글자를 pw 리스트의 커서 위치에 삽입
			}
		}
		for (auto c : pw) //리스트 pw을 순회하며
			cout << c; //리스트의 원소를 모두 출력
		cout << '\n';
	}
}
