#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    char c = cin.get();
    for (int i = 0; i < n; i++) {
        int level = 0;
        int maxLevel = 0;
        unsigned long long result = 1;
        string s;

        getline(cin, s);

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '[') {
                level++;
                maxLevel = max(maxLevel, level);
            }
            else
                level--;
        }
        /*while (true) {
            c = getchar();
            if (c == '\n')
                break;
            if (c == '[') {  // 여는 괄호면 깊이+1
                level++;
                maxLevel = max(maxLevel, level);
            }
            else
                level--;  // 닫는 괄호이면 바로 위 레벨로 이동
        }*/

        for (int j = 0; j < maxLevel; j++) {
            result *= 2;
        }
        cout << result << "\n";
    }

    return 0;
}
