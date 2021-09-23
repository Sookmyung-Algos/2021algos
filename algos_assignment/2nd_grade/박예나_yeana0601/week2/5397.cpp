#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	int n; //test case 개수 입력
	cin >> n;

	for (int i = 0; i < n; i++) { //n개의 test case 입력받아 string 타입으로 저장
		string pw_case;
		cin >> pw_case;
		list<char> L;

		auto cursor = L.begin(); //cursor 지정

		for (auto c : pw_case) { //pw_case의 원소 c를 순서대로 불러옴
			if (c == '<') {
				if (cursor != L.begin()) { //c가 '<' 이고 cursor가 L의 첫번째 원소를 가리키지 않으면 cursor 앞으로 한칸(--)
					cursor--;
				}
			}
			else if (c == '>') {
				if (cursor != L.end()) { //c가 '>'이고 cursor가 L의 마지막 원소의 다음 칸을 가리키지 않으면 cursor 뒤로 한칸(++)
					cursor++;
				}
			}
			else if (c == '-') {
				if (cursor != L.begin()) { //c가 '-'이고 cursor가 L의 첫번째 원소를 가리키지 않으면 cursor 앞의 원소 삭제하고 그 다음 위치 cursor에 저장
					cursor = L.erase(--cursor);
				}
			}
			else {
				L.insert(cursor, c); //cursor 위치에 c 저장
			}
		}
		for (auto c : L) cout << c; //출력
		cout << '\n'; 
	}
}
