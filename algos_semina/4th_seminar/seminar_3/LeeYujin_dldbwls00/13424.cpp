//다시복습할것
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int t;
int maxnum = 10000;
typedef pair<int, int> q;

int main() {
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<q> arr[101];
        int ans[101];
        for (int i = 0; i < 101; i++) ans[i] = 0;

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            arr[a].push_back(q(b, c));
            arr[b].push_back(q(a, c));
        }

        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int s;
            cin >> s;
            int length[101];
            for (int j = 0; j < 101; j++) length[j] = maxnum;

            priority_queue<q, vector<q>, greater<q> > pq;
            pq.push(q(0, s));
            length[s] = 0;
            while (!pq.empty()) {
                int now = pq.top().second;
                pq.pop();

                for (int k = 0; k < arr[now].size(); k++) {
                    int next = arr[now][k].first;
                    if (length[next] > length[now] + arr[now][k].second) {
                        length[next] = length[now] + arr[now][k].second;
                        pq.push(q(length[next], next));
                    }
                }
            }
            for (int j = 1; j <= n; j++)    ans[j] += length[j];

        }

        int result = -1;
        int num;
        for (int i = 1; i <= n; i++) {
            if (result == -1 || ans[i] < result) {
                result = ans[i];
                num = i;
            }
        }
        cout << num << "\n";
    }
    return 0;
}
