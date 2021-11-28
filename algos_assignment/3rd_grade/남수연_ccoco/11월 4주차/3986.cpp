#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int cnt = 0;
    cin >> n;
    for (int u = 0; u < n; u++) {
        stack<char> stack;
        string tmp;
        cin >> tmp;
        int len = tmp.length();
        
        for(int i = 0;i < len;i++) {
            if (stack.size() != 0) {
                if (stack.top() == tmp[i]) {
                    stack.pop();
                } else {
                    stack.push(tmp[i]);
                }
            } else {
                stack.push(tmp[i]);
            }
        }
        if (stack.size() == 0) {
            cnt++;
        }
    }
    printf("%d", cnt);
}
