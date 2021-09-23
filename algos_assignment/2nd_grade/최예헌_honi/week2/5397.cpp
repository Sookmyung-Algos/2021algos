#include <iostream>
#include <list>

using namespace std;

int main(){
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    string password;
    list<char> L;
    int N,i;
    auto cursor=L.end();
    
    cin>>N;                 //테스트 케이스의 개수 입력
    while (N--)
    {
        cin>>password;      //비밀번호 입력
        for (i=0;password[i]!='\0';i++)     //비밀번호를 하나씩 읽음
        {
            if (password[i]=='<')       //<인 경우
            {
                if (cursor!=L.begin())
                    cursor--;           //커서를 왼쪽으로 이동
            }
            else if (password[i]=='>')  //>인 경우
            {
                if (cursor!=L.end())
                    cursor++;           //커서를 오른쪽으로 이동
            }
            else if (password[i]=='-')  //-인 경우
            {
                if (cursor!=L.begin())
                    cursor=L.erase(--cursor);   //삭제
            }
            else            //이외 모든 문자
            {
                L.insert(cursor,password[i]);   //삽입
            }
        }
        for (auto c:L)          //리스트를 c에 할당
            cout<<c;            //c 출력
        cout<<'\n';
        L.clear();              //리스트의 모든 원소 삭제
        cursor=L.end();         //커서 위치 초기화
    }
    return 0;
}
