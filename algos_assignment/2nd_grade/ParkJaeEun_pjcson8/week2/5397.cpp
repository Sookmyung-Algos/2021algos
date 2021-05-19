#include <iostream>
#include <list>

using namespace std;

int main() {
    int N;
    string pw;
    list<char> L;
    
    auto cursor = L.end();

    cin >> N;   

    while (N--)
    {
        cin >> pw;

        for (int i = 0; pw[i] != '\0'; i++)
        {
            if (pw[i] == '<')
            {
                if (cursor != L.begin())    //커서가 맨 앞 x
                    cursor--;               //커서 왼쪽으로 이동
            }
            else if (pw[i] == '>')
            {
                if (cursor != L.end())  //커서가 맨 뒤 x
                    cursor++;           //커서 오른쪽으로 이동
            }
            else if (pw[i] == '-')
            {
                if (cursor != L.begin())    //커서가 맨 앞x
                    cursor = L.erase(--cursor);   //커서 왼쪽 문자 삭제
            }
            else
            {
                L.insert(cursor, pw[i]);   //문자 입력시 L에 넣는다.
            }
        }
        for (auto c : L)        //L 각각 출력  
            cout << c;            
        cout << '\n';

        L.clear();              //리스트 초기화
        cursor = L.end();         //커서 맨 뒤로 보내기.
    }
    return 0;
}
