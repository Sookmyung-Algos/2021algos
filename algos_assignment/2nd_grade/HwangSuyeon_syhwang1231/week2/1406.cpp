//baekjoon 1406 에디터
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void)
{
	string s;
	int n;

	cin >> s;	//문자열과 입력의 개수(n)입력받기
	cin >> n;

	list<char> L;	//받은 문자열을 list로 관리하기 위해 list L 생성

	for (auto c : s)	//입력받은 문자열 s를 list에 하나씩 삽입
		L.push_back(c);

	auto cursor = L.end();	//초기 커서의 위치는 문자열 맨 뒤에

	while (n--)
	{
		char op;	//편집 명령어 받기
		cin >> op;

		if (op == 'P')
		{
			char ch;
			cin >> ch;	//끝에 추가할 문자 입력받기
			L.insert(cursor, ch);
			//cursor++;
		}

		else if (op == 'L')
		{
			if (cursor != L.begin())	//커서의 현재 위치가 맨 앞이 아닐때만 커서를 한 칸 앞으로 이동
				cursor--;
		}

		else if (op == 'D')
		{
			if (cursor != L.end())		//커서의 현재 위치가 맨 뒤가 아닐때만 커서를 한 칸 뒤로 이동
				cursor++;
		}

		else if (op == 'B')
		{
			if (cursor != L.begin())	//커서의 현재 위치가 맨 앞이 아닐 때만
			{
				cursor--;	//커서의 위치를 하나 앞으로 이동해서
				cursor = L.erase(cursor);	//그 자리에 있는 원소 삭제, erase 함수는 삭제한 원소 다음 원소의 iterator 반환
			}
		}
	}
	
	for (auto c : L)	//편집 완료된 list L을 출력
		cout << c;

	return 0;
}
