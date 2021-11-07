#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    int N, M, K, H;
    int X, Y;

    
    cin >> T;
    vector<int> v(T);

    for (int i = 0; i < T; i++)
        scanf("%d", &v[i]);
    
    sort(v.begin(), v.end());
    cin >> T;

    vector<int> answer(T);
    for (int i = 0; i < T; i++) {
        cin >> K;
        auto upper = upper_bound(v.begin(), v.end(), K);
        auto lower = lower_bound(v.begin(), v.end(), K);

        answer[i] = upper - lower;
    }

    for (auto n : answer)
        cout << n << " ";
        
    return 0;
}
