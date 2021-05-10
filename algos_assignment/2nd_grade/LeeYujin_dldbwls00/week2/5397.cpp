#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	int n;
	cin >> n; // 테스트 케이스의 개수
	
	while (n--) {
		string test; //테스트 케이스
		cin >> test;
		list<char> L; // 리스트에 넣어 관리
		for (auto c : test) L.push_back(c); //뒤쪽으로 원소 삽입

		list<char> password; // 비밀번호만 담음(기호 제외)
		auto cursor = password.end(); // 커서의 초기 위치

		for (int i = 0; i < test.length(); i++) {
			if (test[i] == '<') { // 왼쪽으로 1만큼 이동
				if (cursor != password.begin())	cursor--;
			}
			else if (test[i] == '>') { // 오른쪽으로 1만큼 이동
				if (cursor != password.end())	cursor++;
			}
			else if (test[i] == '-') { // 지우기
				if (cursor != password.begin())	cursor = password.erase(--cursor);;
			}
			else { // 입력한 문자 삽입
				password.insert(cursor, test[i]);
			}
		}
		for (auto c : password) cout << c;
		cout << '\n';
		password.clear();
	}
	return 0;
}
