// 11279 (실버2) 최대 힙

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;  // 연산의 개수
    int x;  // 연산에 대한 정보
    cin >> N;

    priority_queue<int>pq;  // 내림차순으로 정렬해주는 큐

    while (N--) {
        cin >> x;

        if (x == 0) {
            if (pq.empty())
                cout << "0" << '\n';
            else {
                cout << pq.top() << '\n';   // 가장 위에 있는 값 = 가장 큰 값 출력
                pq.pop();
            }
        }
        else
            pq.push(x);
    }

    return 0;
}
