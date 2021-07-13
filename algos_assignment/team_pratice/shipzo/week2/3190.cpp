#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[12];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, op, max_num = -2000000000, min_num = 2000000000;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < 4; i++) {
        cin >> op;
        while (op--) v.push_back(i);
    }

    do {
        int tmp[12];
        for (int i = 0; i < n; i++)
            tmp[i] = num[i];
        for (int i = 0; i < n - 1; i++) {
            switch (v[i]) {
            case 0: tmp[i + 1] = tmp[i] + tmp[i + 1]; break;
            case 1: tmp[i + 1] = tmp[i] - tmp[i + 1]; break;
            case 2: tmp[i + 1] = tmp[i] * tmp[i + 1]; break;
            case 3: tmp[i + 1] = tmp[i] / tmp[i + 1]; break;
            }
        }
        max_num = max(max_num, tmp[n - 1]);
        min_num = min(min_num, tmp[n - 1]);

    } while (next_permutation(v.begin(), v.end()));

    cout << max_num << '\n' << min_num << '\n';

    return 0;
}
