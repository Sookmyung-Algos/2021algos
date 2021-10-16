#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    long long w, h, L;
    scanf("%lld%lld%lld", &w, &h, &L);
    long long ans = 2 * L;
    long long tmp = 0;
    for (long long i = 1; i < L; ++i) {
        tmp += (long long) sqrt((long long)L * L - i * i);
    }
    ans += tmp * 3;

    if (min(w, h) >= L) {
        printf("%lld", ans); return 0;
    }

    long long one1 = 0;
    long long one2 = 0;
    long long r1 = L - h, r2 = L - w;
    for (long long i = 0; i <= r1; ++i)
        one1 += (long long) sqrt(r1 * r1 - i * i);
    for (long long i = 0; i <= r2; ++i)
        one2 += (long long) sqrt(r2 * r2 - i * i);

    if (w < L) {
        if (h < L) {
            ans += one1 + one2;
            if (h + w >= L) {
                printf("%lld", ans);
            }
            else {
                long long inter = 0, y_of_one1 = 0, y_of_one2 = -1;
                long long i = w + 1;
                bool flag = false;
                for (; ; ++i) {
                    y_of_one1 = (long long) sqrt(r1 * r1 - i * i) + h;
                    y_of_one2 = (long long) sqrt(r2 * r2 - (i - w) * (i - w));
                    if (y_of_one2 - h <= 0)
                    {
                        flag = true;
                        break;
                    }
                    if (y_of_one2 >= y_of_one1) break;
                    inter += y_of_one2 - h; 
                }
                if (!flag)
                {
                    for (; i <= L - h; ++i)
                    {
                        y_of_one1 = (long long)sqrt(r1 * r1 - i * i) + h;
                        if (y_of_one1 - h <= 0) break;
                        inter += y_of_one1 - h;
                    }
                }
                ans -= inter;
                // cout << "inter: " << inter << endl;
                printf("%lld", ans);
            }
            return 0;
        }
        ans += one2;
        printf("%lld", ans);
        return 0;
    }
    ans += one1;
    printf("%lld", ans);
    return 0;
}
