#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) {
	int nCases;	//테스크 케이스의 개수

	cin >> nCases;	//테스크 케이스 개수 입력받기
	for (int i = 0; i < nCases; i++) {
		string inputStr;	//입력받을 문자열 
		list<char> ansList;		//정답을 저장할 리스트

		cin >> inputStr;
		auto cursor = ansList.begin();	//커서값은 새로 만든 list의 시작위치

		int index = 0;	//string s의 인덱스값
		int length = inputStr.size();

		while (index < length) {	//string을 끝까지 돌면서 진행
			char c = inputStr[index];	//문자 받아오기
			
			if (c == '<') {
				if (cursor != ansList.begin())
					cursor--;
			}
			else if (c == '>') {
				if (cursor != ansList.end())
					cursor++;
			}
			else if (c == '-') {
				if (cursor != ansList.begin()) {
					cursor = ansList.erase(--cursor);
				}
			}
			else {
				ansList.insert(cursor, c);
			}
			index++;	//string의 인덱스 값 증가(다음 문자 읽기 위해)
		}

		for (auto c : ansList)
			cout << c;

		cout << "\n";
	}
	return 0;
}
