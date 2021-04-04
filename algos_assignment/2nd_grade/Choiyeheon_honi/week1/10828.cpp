#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N,num;
    string x;
    stack<int> s;
    cin>>N;                             //명령의 수
    for (int i=0;i<N;i++){
        cin>>x;                         //명령 입력
        if (x=="push"){                 //push일 때
            cin>>num;                   //push할 값 num에 입력
            s.push(num);                //num의 값 스택에 push
        }
        
        else if (x=="pop"){             //pop일 때
            if (s.empty())              //스택이 비었을 때
                cout<<-1<<'\n';         //-1 출력
            else{
                cout<<s.top()<<'\n';    //스택의 top 출력
                s.pop();                //스택 pop
            }
        }
            
        else if (x=="size")             //size일 때
            cout<<s.size()<<'\n';       //스택의 size 출력

        else if (x=="empty")            //empty일 때
            cout<<s.empty()<<'\n';      //스택이 비었을 때는 1, 아닐 때는 0 출력
        
        else if (x=="top"){             //top일 때
            if (s.empty())              //스택이 비었을 때
                cout<<-1<<'\n';         //-1 출력
            else
                cout<<s.top()<<'\n';    //스택의 top 출력
        }
    }
}
