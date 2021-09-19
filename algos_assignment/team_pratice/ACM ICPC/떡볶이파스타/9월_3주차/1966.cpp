#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    int cnt = 0;
    while(t--){
        int n, m; //문서의 개수, 문서 위치
        cin >> n >> m;

        cnt = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq; // 우선순위큐
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            q.push({ i, temp });
            pq.push(temp); //우선순위가 높을수록 뒤에
        }
        while (!q.empty()) {
            int idx = q.front().first;
            int value = q.front().second;

            q.pop();

            if (pq.top() == value) {
                pq.pop();
                ++cnt;
                if (idx == m) {
                    cout << cnt << "\n";
                    break;
                }
            }
            else q.push({ idx,value }); // q와 pq의 front가 같지 않은 경우
        }
    }
    return 0;
}
