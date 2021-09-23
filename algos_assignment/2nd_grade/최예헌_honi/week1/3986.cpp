#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    string x;
    int N, len;
    int word=0;
    cin>>N;                         //단어의 수 입력
    
    for (int i=0;i<N;i++){
        cin>>x;                     //단어 입력
        len=x.length();             //string 라이브러리의 함수: string(단어)의 길이값 변수 len에 저장
        stack<char> s;

        for (int j=0;j<len;j++){
            if (!s.empty()){                    //스택이 비었을 때
                if (s.top()==x[j]) {            //스택의 top이 x배열의 j 인덱스 값과 같을 때
                    s.pop();                    //스택 pop
                }
                else
                    s.push(x[j]);               //스택에 j 인덱스 값 push
            }
            else
                s.push(x[j]);                   //스택에 j 인덱스 값 push
        }
        if (s.empty())                          //반복이 종료되고 스택이 비었을 때
            word++;                             //좋은 단어의 개수 1 중가
    }
    cout<<word;                                 //word 값 출력
}
