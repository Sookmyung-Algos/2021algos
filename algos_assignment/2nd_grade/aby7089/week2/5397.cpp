#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	string s;
	char q,m;
	int n;
	cin >> n;
	
	while (n--) {
		cin >> s;
		list <char> l;
		list <char>::iterator itr = l.end(); //커서 처음 위치
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<') {     //<일 때는 커서를 하나 앞으로 이동
				if (itr != l.begin())
					itr--;
			}
			else if (s[i] == '>') {  //>일 때는 뒤로 하나 이동
				if (itr != l.end())
					itr++;
			}
			else if (s[i] == '-') {  //-일 때는 왼쪽에 있는 글자를 삭제
				if (itr != l.begin())
					itr = l.erase(--itr);
			}
			else         
				l.insert(itr, s[i]);
		}
		for (auto it = l.begin(); it != l.end(); it++)  //시작부터 끝까지 출력
			cout << *it;
		cout << '\n';
		l.clear();     //새로운 문자열을 받기 위해 초기화
	}
}
