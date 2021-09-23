#include <iostream>
#include <list>

using namespace std;

int main(){
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    string editor;
    int M;
    char op,x;
    list<char> L;
    cin>>editor;                  //문자열 입력
    
    
    for (auto c:editor)           //editor의 문자열을 c 리스트에 하나씩 할당
        L.push_back(c);           //리스트 맨 뒤에 c 추가
    auto cursor = L.end();        //커서는 문장의 맨 뒤에 위치
    cin>>M;                       //명령어 수 입력
    
    while (M--){
        cin>>op;                  //명령어 입력
        if (op=='P'){
            cin>>x;                   //추가할 x 입력
            L.insert(cursor,x);      //커서 왼쪽 위치에 x 추가
        }
        else if (op=='L'){
            if (cursor!=L.begin())      //커서가 문장 맨 앞이 아닐 때
                cursor--;       //커서 왼쪽으로 한 칸 옮김
        }
        else if (op=='D'){
            if (cursor!=L.end())    //커서가 문장 맨 뒤가 아닐 때
                cursor++;       //커서 오른쪽으로 한 칸 옮김
        }
        else{
            if (cursor!=L.begin())      //커서가 문장 맨 앞이 아닐 때
                cursor=L.erase(--cursor);       //커서 왼쪽의 문자 삭제
        }
    }
    for (auto c:L)      //리스트를 c에 하나씩 할당
        cout<<c;        //c값 출력
}
