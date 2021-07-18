// 9372 상근이의 여행

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T; 
    int N, M;
    int a, b;
    cin >> T; // 테스트 케이스의 수

    while (T > 0) {
        cin >> N >> M; // 국가의 수, 비행기 종류

        for (int i = 1; i <= M; i++) { // 비행기 수만큼 지역 입력
            cin >> a >> b; // 지역 ab 왕복 가능
        }
        cout << (N - 1) << "\n";
        T--;
    }

    return 0;
}


