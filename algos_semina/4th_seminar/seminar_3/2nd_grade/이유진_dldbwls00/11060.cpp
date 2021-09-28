#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(1000, -1);
    for (int i = 0; i < n; i++) cin >> v[i];

    bool impossible = false;
    int cnt = 0, idx = 0;

    while (idx < n - 1) {
        if (v[idx] == -1 || v[idx] == 0) { // 1 1 0인 경우
            impossible = true;
            break;
        }
        int temp = 0;
        if (v[idx] != 1) {
            for (int i = 0; i < v[idx] - 1; i++) { // 갈 횟수 결정(max값)
                if (v[idx] == 1) {
                    temp = 1;
                    break;
                }
                temp = v[idx];
                temp = max(temp, v[idx + 1]);
            }
        }
        else temp = 1;
        idx += temp;
        cnt++;
    }
    if (impossible == true)  cout << "-1";
    else cout << cnt;
    return 0;
} //
