//STL 리스트 구현
#include <iostream>
#include <string>
#include <list>

using namespace std;
int main(void) {

    string editor;
    cin >> editor;
    list<char> L;

    for (auto c : editor) L.push_back(c); //에디터 속 문자열을 c형태로 쪼개서 하나씩 넣기
    int q;
    list<char>::iterator cursor = L.end();
    cin >> q;

    while (q--) {
        char op;
        cin >> op;
        if (op == 'P') { //값을 받아서 넣기
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
        else if (op == 'L') { //cursor가 처음이 아니면 앞으로 옮기기
            if (cursor != L.begin()) cursor--;
        }
        else if (op == 'D') { //cursor가 마지막이 아니면 뒤로 옮기기
            if (cursor != L.end()) cursor++;
        }
        else { //'B' //cursor가 처음이 아니면 문자 삭제
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for (auto c : L) cout << c;
}
