#include <algorithm>
#include <iostream>
#define MAX 10000 + 1
using namespace std;

int t, n;
string num[MAX];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> num[i];
        sort(num, num + n);

        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            string tmp = num[i + 1].substr(0, num[i].length());
            if (num[i] == tmp) {
                flag = false;
                break;
            }
        }
        (flag) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
