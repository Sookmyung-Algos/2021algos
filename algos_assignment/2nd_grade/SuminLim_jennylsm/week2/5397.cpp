#include <iostream>
#include <list>

using namespace std;

int main(void) {
    int test;
    cin >> test;  //테스트할 케이스의 개수를 입력

    while (test--)
    {
        string in;
        cin >> in;  //문자열 입력
        list<char> L;    
        list<char>::iterator c = L.begin();

        for (int i = 0; i < in.length(); i++)
        {
            if (in[i] == '<')
            {
                if (c != L.begin())
                    c--;

            }
            else if (in[i] == '>')  //화살표를 입력한 경우
            {
                if (c != L.end())
                    c++;
            }
            else if (in[i] == '-')    //백스페이스를 입력한 경우
            {
                if (c != L.begin()) {

                    c--;
                    c = L.erase(c);

                }
            }
            else
                L.insert(c, in[i]);   //나머지경우는 그대로 입력
        }
        for (auto a : L) cout << a;    //반복문을 통해 출력
        cout << "\n";

    }

}
