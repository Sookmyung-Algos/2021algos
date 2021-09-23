// 20923: 숫자 할리갈리 게임(Silver 1)
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    deque<int> dodo;
    deque<int> su;
    deque<int> dGround;
    deque<int> sGround;
    
    for(int i=0;i<N;i++){
        int d, s;
        cin >> d >> s;
        dodo.push_back(d);
        su.push_back(s);
    }
    
    // 게임 진행
    bool isDodoTurn = true;  // 차례
    int turn = 0;
    
    while(1){
        if(turn>=M)
            break;
        if(isDodoTurn){  // 도도 차례
            dGround.push_back(dodo.back());  // 2.카드 내기
            dodo.pop_back();
            
            if(dodo.empty())  // 덱 비었는지
                break;
            
            if(dGround.back() == 5){  // 3. 종 치기(도도)
                while(!sGround.empty()){  // 4. 그라운드의 카드 가져가기
                    dodo.push_front(sGround.front());
                    sGround.pop_front();
                }
                while(!dGround.empty()){
                    dodo.push_front(dGround.front());
                    dGround.pop_front();
                }
            }
            
            if(!sGround.empty() && !dGround.empty() && dGround.back()+sGround.back() == 5){  // 3.종치기(수연) 
                while(!dGround.empty()){  // 4. 그라운드의 카드 가져가기
                    su.push_front(dGround.front());
                    dGround.pop_front();
                }
                while(!sGround.empty()){
                    su.push_front(sGround.front());
                    sGround.pop_front();
                }
            }
            turn++;
        }
        else{  // 수연 차례
            sGround.push_back(su.back());  // 2. 카드 내기
            su.pop_back();
            
            if(su.empty())  // 덱 비었는지
                break;
            
            if(dGround.back()+sGround.back() == 5 && !sGround.empty() && !dGround.empty()){  // 3.종치기(수연)
                while(!dGround.empty()){  // 4.그라운드 더미 가져가기
                    su.push_front(dGround.front());
                    dGround.pop_front();
                }
                while(!sGround.empty()){
                    su.push_front(sGround.front());
                    sGround.pop_front();
                }
            }
            if(sGround.back() == 5){  // 3. 종 치기(도도)
                while(!sGround.empty()){  // 4. 그라운드의 카드 가져가기
                    dodo.push_front(sGround.front());
                    sGround.pop_front();
                }
                while(!dGround.empty()){
                    dodo.push_front(dGround.front());
                    dGround.pop_front();
                }
            }
            turn++;
        }
        
        isDodoTurn = isDodoTurn ? false:true;
    }
    
    if(su.size() == dodo.size()){
        cout << "dosu";
    }
    else{
        if(su.size()>dodo.size())
            cout << "su";
        else
            cout << "do";
    }
    
    return 0;
}
