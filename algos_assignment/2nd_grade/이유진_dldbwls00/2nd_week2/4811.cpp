#include <iostream> //다시볼것
#include <cstring>
using namespace std;

int n;
long long dp[61][61];

long long solve(int one, int half) {
    if (!one) return 1;

    long long& ans = dp[one][half];
    if (ans != -1) return ans;

    ans = 0;

    if (one > 0)    ans += solve(one - 1, half + 1);
    if (half > 0)   ans += solve(one, half - 1);

    return ans;
}

int main() {
    cin >> n;
    while (n) {
        memset(dp, -1, sizeof(dp)); //초기화
        cout << solve(n - 1, 1) << "\n";
        cin >> n;
    return 0;
}
