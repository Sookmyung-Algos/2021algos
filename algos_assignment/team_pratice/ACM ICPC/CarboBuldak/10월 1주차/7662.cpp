#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int T;
    bool valid[1000001];
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int k;
        cin >> k;
        memset(valid, false, sizeof(valid));
        priority_queue<pair<int, int>> min_q;
        priority_queue<pair<int, int>, vector<pair<int, int >>, greater<pair<int, int>>> max_q;
        int idx = 0;
        for (int j = 0; j < k; j++) {
            char op; int tmp;
            cin >> op;
            if (op == 'I') {
                cin >> tmp;
                min_q.push({tmp, idx});
                max_q.push({tmp, idx++});
            } else if (op == 'D') {
                cin >> tmp;
                if (tmp == 1) {
                    while (!min_q.empty() && valid[min_q.top().second])
                                            min_q.pop();

                    if (!min_q.empty()) {
                        valid[min_q.top().second] = true;
                        min_q.pop();
                    }
                } else if (tmp == -1) {
                    while (!max_q.empty() && valid[max_q.top().second])
                        max_q.pop();

                    if (!max_q.empty()) {
                        valid[max_q.top().second] = true;
                        max_q.pop();
                    }
                }
            }
        }

        while (!min_q.empty() && valid[min_q.top().second])
            min_q.pop();
        while (!max_q.empty() && valid[max_q.top().second])
            max_q.pop();

        if (max_q.empty() || min_q.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            cout << min_q.top().first << ' ' << max_q.top().first << '\n';
        }
    }
    return 0;
}
