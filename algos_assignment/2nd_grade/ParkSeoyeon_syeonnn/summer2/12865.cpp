// 12865 평범한 배낭

#include <iostream>
#include <algorithm>
using namespace std;

int b[100001];  // 가방 용량
int w[101];     // 물건의 무게
int v[101];     // 물건의 가치

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 1; j--) {
            if (w[i] <= j) {
                b[j] = max(b[j], b[j - w[i]] + v[i]);
            }   // 물건의 무게가 현재 가방의 용량보다 작거나 같을 때는 i번째 물건의 선택 유무의 경우들을 비교
            else
                continue;   // 물건의 무게가 현재 가방의 용량보다 클 때는 기존 최대 가치 유지
        }
    }

    cout << b[k] << "\n";

    return 0;
}
