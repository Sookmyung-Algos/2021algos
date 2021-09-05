//AC
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef double ld;
ld p[101010];
int main() {
    int N;
    ld ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        ans += p[i];
    }
    for (int i = 0; i < N - 1; i++) {
        ans += (p[i] * (1 - p[i + 1]) + p[i + 1] * (1 - p[i]));
    }
    printf("%.9lf", ans);
    return 0;
}