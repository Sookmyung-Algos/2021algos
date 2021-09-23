#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;  // 수열을 이루는 정수 개수
    vector<char> ans; // +와 -로 이루어지는 답
    stack<int>s;
    int max = 1;

    cin >> n;

    while(n--){
        int x;  // 수열을 이루는 정수
        cin >> x;  

        while (x >= max) {
            s.push(max);
            max++;
            ans.push_back('+');
        }
        if (s.top()==x) {
            s.pop();    
            ans.push_back('-');
        }
        else {  
            cout << "NO";
            return 0;
        }
    }
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
