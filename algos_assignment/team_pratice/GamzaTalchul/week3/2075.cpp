#include<iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>>pq;
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int e;
        cin >> e;
        pq.push(e);
        if (pq.size() > n) pq.pop();
    }
    int ans;
    cout << pq.top();
}
