#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, w, sum = 200001;
    vector<int> ablty;

    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> w;
        ablty.push_back(w); 
    }   // 개인의 코딩 역량 입력 받아 벡터ablty에 넣음
    sort(ablty.begin(), ablty.end());   // 코딩 역량 오름차순 정렬

    for (int i = 0; i < 2 * n; i++) {
        sum = min(sum, ablty[i] + ablty[2 * n - 1 - i]);    // 반복문에 의해 이전의 최솟값과 새로운 값을 비교하며 최종적인 최솟값 구함
    }
    cout << sum;
    return 0;
}
