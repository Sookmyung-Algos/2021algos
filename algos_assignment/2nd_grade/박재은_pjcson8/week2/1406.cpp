#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void)
{
	string editor;
	int n;

	cin >> editor;	//문자열 입력
	cin >> n;		//개수 입력

	list<char> L;

	for (auto c : editor)	//editor를 list에 하나씩 넣기.
		L.push_back(c);
	auto cursor = L.end();	//처음에 커서를 문자열 맨 뒤에 두기.

	while (n--)
	{
		char op;	
		cin >> op;

		if (op == 'P')
		{
			char x;
			cin >> x; // 뒤에 입력된 문자 입력받기.	
			L.insert(cursor, x); //입력받은 x를 커서 앞에 삽입.
		}

		else if (op == 'L')
		{
			if (cursor != L.begin())	//커서가 맨앞 x
				cursor--;				//커서 왼쪽으로 이동.
		}

		else if (op == 'D')
		{
			if (cursor != L.end())		//커서가 맨 뒤 x
				cursor++;				//커서 오른쪽으로 이동.
		}

		else
		{
			if (cursor != L.begin())		//커서가 맨앞 x
				cursor = L.erase(--cursor);	//커서 왼쪽 문자 삭제.
		}
	}

	for (auto c : L)	//L의 값 각각을 출력.
		cout << c;

	return 0;
}
