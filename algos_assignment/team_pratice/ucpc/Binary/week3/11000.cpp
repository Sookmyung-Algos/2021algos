#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
    vector<pair<int, int>>v;
    priority_queue<int, vector<int>,greater<int>>pq; //끝나는 시간, 강의실 번호
    int n, s, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        v.push_back({ s,t });
    }
    sort(v.begin(), v.end());
    
    pq.push(v[0].second); //끝나는 시간
    for (int i = 1; i < n; i++) {
        if (pq.top() <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i].second);
    }
    cout << pq.size();
}
