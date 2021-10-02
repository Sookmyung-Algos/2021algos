#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(int i, int j) {
    return i > j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K, cnt = 0;

    cin >> N >> K;
    vector<int> kind(N);

    for (int i = 0; i < N; i++) {
        cin >> kind[i];
    }

    sort(kind.begin(), kind.end(), cmp);

    for (int i = 0; i < N; i++) {
        while (K - kind[i] >= 0) {
            cnt++;
            K -= kind[i];
        }
    }
    cout << cnt << "\n";
}
