#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string str;
		cin >> str;
		list<char> answer;

		list<char>::iterator cursor = answer.end(); // 처음 커서의 위치
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (cursor == answer.begin()) continue; 
				// 만약 커서가 처음에 있으면 움직이지 않고 넘기기
				cursor--;
				// 만약 처음이 아니라면 왼쪽으로 옮기기
			}
			else if (str[i] == '>') {
				if (cursor == answer.end()) continue;
				// 만약 커서가 끝에 있으면 움직이지 않고 넘기기
				cursor++;
				// 끝이 아니라면 오르쪽으로 하나 옮기기
			}
			else if (str[i] == '-') {
				if (cursor == answer.begin()) continue;
				cursor = answer.erase(--cursor);
				// 지웠으면 반환되는 cursor 받아서 값 바꿔주기
			}
			else {
				answer.insert(cursor, str[i]);
			}
		}
		for (auto cnt = answer.begin(); cnt != answer.end(); cnt++) {
			cout << *cnt;
		}
		cout << '\n';
		answer.clear(); // 마지막에 초기화해주기
	}
	return 0;
}
