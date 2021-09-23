#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> tpq;

int main(){
    int n, s, t;
    int fin, cnt=1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s >> t;
        pq.push(make_pair(s, t));
    }
    while(!pq.empty()){
        pair<int,int> p=pq.top();
        s=p.first; t=p.second;
        pq.pop();
        if(!tpq.empty()){
            fin=tpq.top();
            if(fin<=s){
                tpq.pop();
            }
            else{
                cnt++;
            }
        }
        tpq.push(t);
    }
    cout << cnt;
}
