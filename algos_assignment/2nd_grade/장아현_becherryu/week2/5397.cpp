//연결리스트
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        list<char> P;

        list<char>::iterator cursor = P.end();

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '-') { //글자 지우기
                if (cursor == P.begin()) continue;
                cursor = P.erase(--cursor);
            }
            else if (str[i] == '<') { //왼쪽
                if (cursor == P.begin()) continue;
                cursor--;
            }
            else if (str[i] == '>') { //오른쪽
                if (cursor == P.end()) continue;
                cursor++;
            }
            else { //마지막이 아니라면 오른쪽 한 칸 이동
                P.insert(cursor, str[i]);
                continue;
            }
        }
        for (auto c = P.begin(); c != P.end(); c++) cout << *c;
        cout << '\n';
    }
    return 0;
}
