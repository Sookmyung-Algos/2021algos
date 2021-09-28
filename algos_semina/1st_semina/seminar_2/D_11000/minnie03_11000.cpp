#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
 
using namespace std;
 
pair<int, int> p[200010];
priority_queue<int, vector<int>, greater<int>> pq;
int N, arr[200010], cnt;
 
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> p[i].first >> p[i].second;
    }
 
    sort(p+1, p+N+1);
 
    pq.push(p[1].second);
 
    for(int i=2; i<=N; i++){
        if(pq.top() <= p[i].first){
            pq.pop();
            pq.push(p[i].second);
        }
        else{
            pq.push(p[i].second);
        }
    }
 
    cout << pq.size() << endl;
 
    return 0;
}
