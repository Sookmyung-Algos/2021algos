#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, temp, mean, mode = 0, min, max = 0;
    bool isSecond = false;

    cin >> N;
    vector<int> v(N);
    vector<int> v2(8001, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        mean += v[i];
        temp = v[i]+ 4000;
        v2[temp]++;
        if (v2[temp] > max)
            max = v2[temp];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < 8001; i++) {
        if (v2[i] == max) {
            mode = i-4000;
            if (isSecond)
                break;
            isSecond = true;
        }
    }

    cout << round(mean / (double)N) << '\n';
    cout << v[round(N / 2)] << '\n';
    cout << mode << '\n';
    min = v[0];
    max = v[v.size() - 1];
    cout << max - min << '\n';
}
