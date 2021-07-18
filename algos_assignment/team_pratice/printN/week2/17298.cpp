#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> num(n);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) 
        cin >> num[i];

    stack<int> s;
    s.push(0);

    for (int i = 1; i < n; i++) {
        if (s.empty()) 
            s.push(i);
        // 오큰수 있는 경우
        while (!s.empty() && num[s.top()] < num[i]) { // 현재값과 후보값 비교
            ans[s.top()] = num[i]; // 오큰수 업데이트
            s.pop();
        }
        s.push(i); // 현재값을 후보로
    }

    // 오큰수 없는 경우
    while (!s.empty()) { 
        ans[s.top()] = -1; // -1로 업데이트
        s.pop();
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
