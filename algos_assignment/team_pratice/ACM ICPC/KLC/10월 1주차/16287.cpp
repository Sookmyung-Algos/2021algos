#include <iostream>
#include <algorithm>
using namespace std;

int w, n;
int input[5000];
bool dp[400001];

int main() {
    
    cin >> w >> n;

    for (int i = 0; i < n; i++)
        cin >> input[i];

    sort(input, input + n);

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < i; j++)
            dp[input[i] + input[j]] = true;

        for (int j = i + 2; j < n; j++) {
            int t = w - input[i + 1] - input[j];
            if (t < 0)
                break;
            if (t <= 400000 && dp[t]) {
                printf("YES");
                return 0;
            }
        }

    }
    printf("NO");
}
