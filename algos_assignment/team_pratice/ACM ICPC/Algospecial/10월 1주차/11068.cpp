#include <iostream>
#include <cmath>
using namespace std;

bool is(long long num, long long n) {
    int digit = 0;
    for (int i = 0; ; ++i)
        if (n < (long long) pow(num, i)) {
            digit = i - 1;
            break;
        }
    for (int i = 0; i <= digit / 2; ++i) {
        if (n / (long long)pow(num, digit - i) % num != n / (long long)pow(num, i) % num)
            return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, ans = 0;
        scanf("%d", &n);
        for (int num = 2; num <= 64; ++num) {
            if (is(num, n)) {
                ans = 1; break;
            }
        }
        printf("%d\n", ans);
    }
}
