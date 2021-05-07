#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector <pair<int,int>> v(n);
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for (int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(),v.end());
    
    pq.push(v[0].second);
    for (int i=1;i<n-1;i++){
        if (pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        } else {
            pq.push(v[i].second);
        }
    }
    cout << pq.size() << '\n';
    return 0;
}
