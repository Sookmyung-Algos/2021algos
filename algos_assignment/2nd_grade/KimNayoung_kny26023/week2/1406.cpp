#include <iostream>
#include <list>
using namespace std;

int main() {
	char line[100000];
	char op;
	int i, M, pos=0;
	list<char> L;
	cin >> line;
	for (int i = 0; line[i] != NULL; i++) L.push_back(line[i]);
	//line[i]가 NULL이 되기 전까지 L이라는 리스트에 넣어준다.
	auto cursor = L.end();
	//cursor는 처음에는 가장 끝에 있어야 한다.
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> op;
		if (op == 'P') {
			char editor;
			cin >> editor;
			cursor= L.insert(cursor, editor);
			cursor++;
			//글자를 더해주고 커서를 옮겨준다.
		}
		else if (op == 'L') {
			if (cursor != L.begin())
				cursor--;
			//커서를 옮긴다.
		}
		else if (op == 'D') {
			if (cursor!=L.end())
				cursor++;
			//커서를 옮긴다.
		}
		else {
			if (cursor != L.begin()) {
				cursor= L.erase(--cursor);
				//글자를 하나 지우고 커서를 옮겨준다.
			}
		}
	}
	while (!L.empty()) {
		cout << L.front();
		L.pop_front();
	}
	//L에 있는 것들을 앞에서부터 print해준다.
	return 0;
}
