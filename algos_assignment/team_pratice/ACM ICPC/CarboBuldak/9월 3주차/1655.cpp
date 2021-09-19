#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
}

int main(){
    init();
    priority_queue<int, vector<int>, greater<int>> min_q;
    priority_queue<int, vector<int>, less<int>> max_q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (min_q.size() == max_q.size()) {
            max_q.push(x);
        } else {
            min_q.push(x);
        }
        if (!min_q.empty() && max_q.top() > min_q.top()) {
            int maxv = max_q.top();
            int minv = min_q.top();
            max_q.pop();
            min_q.pop();
            max_q.push(minv);
            min_q.push(maxv);
        }
        cout << max_q.top() << '\n';
    }
}
