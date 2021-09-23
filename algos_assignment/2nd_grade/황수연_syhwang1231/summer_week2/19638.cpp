// 19638 센티와 마법의 뿅망치 (Silver 1)
#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N,H,T;
    priority_queue<int> pq;
    cin >> N >> H >> T;
    for(int i=0;i<N;i++){
        int p;
        cin >> p;
        pq.push(p);
    }
    if(pq.top() < H){  // 모두 센티보다 작은 경우
        cout << "YES\n0";
        return 0;
    }
    for(int i=0;i<T;i++){
        int h = pq.top();
        pq.pop();
        h = max(1,h/2);
        pq.push(h);
        if(pq.top() < H){
            cout << "YES\n" << i+1;
            return 0;
        }
    }
    cout << "NO\n" << pq.top();
    return 0;
}
