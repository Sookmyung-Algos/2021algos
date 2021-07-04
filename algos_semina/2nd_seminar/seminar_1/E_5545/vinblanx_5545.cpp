#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int i, int j) {
    return i > j;
}

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<int> d;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        d.push_back(t);
    }
    sort(d.begin(), d.end(), cmp);

    int perCal = C / A; //1원 당 도우의 열량
    int totalP = A; //총 가격
    int totalCal = C; //총 열량

    int best = perCal; //초기화

    for (int i = 0; i < N; i++) {
        totalP += B;
        totalCal += d[i];
        if (best < totalCal / totalP) {
            best = totalCal / totalP;
        }
    }

    cout << best;

}
