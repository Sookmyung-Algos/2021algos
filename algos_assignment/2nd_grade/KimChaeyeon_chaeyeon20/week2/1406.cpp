#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();
	
	string edit;  //편집기에 입력되어 있는 문자열
	cin >> edit;
	
	int num; //명령어 개수
	list <char> li;
	for (auto c : edit) li.push_back(c);
	auto cur = li.end();
	cin >> num;
	for (int i = 0; i < num; i++) {
		char op;
		cin >> op;
		if (op == 'P') {
			char x;
			cin >> x;
			li.insert(cur, x);
		}
		else if (op == 'L') {
			if (cur == li.begin()) continue;
			cur--;
		}
		else if (op == 'D') {
			if (cur == li.end()) continue;
			cur++;
		}
		else if (op == 'B') {
			if (cur == li.begin()) continue;
			cur = li.erase(--cur);
		}
	}
	for (auto c : li) cout << c;
	return 0;
}
