#include <iostream>
#include <stack>

using namespace std;

int building[80005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int n; 
    stack<int> s;
    long long ans = 0;

    cin >> n; 

    for (int i = 0; i < n; i++) { 
        cin >> building[i];
    } 

    for (int i = 0; i < n; i++) { 
        while (!s.empty() && s.top() <= building[i]) {
            s.pop();    // top 제거
        }
        s.push(building[i]);

        ans += s.size() - 1;    // s의 top은 왼쪽의 size-1 개의 빌딩에 옥상이 보여짐
    } 

    cout << ans << "\n"; 
    return 0;
}
