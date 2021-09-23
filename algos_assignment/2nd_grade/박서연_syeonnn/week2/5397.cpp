#include <iostream> 
#include <list>
#include <string>
using namespace std;

int main(void) {

	int n;
	cin >> n; // 테스트 케이스의 개수

	while (n--) { // 테스트 케이스 개수만큼 반복
	
		string test;
		cin >> test;
		list<char> L;
		for (auto c : test) L.push_back(c);

		list<char> password;
		auto cursor = password.end();
    // 배열과 커서 위치 설정

		for (int i = 0; i < test.length(); i++) {
			if (test[i] == '<') {
				if (cursor != password.begin())	cursor--;
			} // 커서가 가장 앞에 았지 않다면 왼쪽으로 옮김
			else if (test[i] == '>') {
				if (cursor != password.end())	cursor++;
			} // 커서가 가장 끝에 있지 않다면 오른쪽으로 옮김
			else if (test[i] == '-') {
				if (cursor != password.begin())	cursor = password.erase(--cursor);;
			} // 커서가 가장 앞에 있지 않다면 삭제 실행 후 커서 위치 바뀜
			else {
				password.insert(cursor, test[i]);
			} // 커서 위치에 test 배열 요소 삽입
		}

		for (auto c : password) cout << c;
		cout << '\n';
		password.clear(); // password 초기화
	}
	return 0;
}
