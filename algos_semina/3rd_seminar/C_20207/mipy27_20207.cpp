#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int s, e;

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first < b.first) return false;
        else if (a.first == b.first) {
            if (a.second > b.second) return false;
            else return true;
        }
        else return true;
    }
};

priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
bool check[1001][366];
int h_max[366] = { 0, };
bool flag = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        pq.push({ s,e });
    }

    //int cur_start=0, cur_end=0;
    while (!pq.empty()) {
        int height = 1;
        while (height <= n) {
            int cur_start = pq.top().first;
            int cur_end = pq.top().second;
            pq.pop();

            while (check[height][cur_start]) { //이미 체크되어 있으면
                height++;
            }

            for (int i = cur_start; i <= cur_end; i++) {
                check[height][i] = true;
                h_max[i] = max(h_max[i], height);
                flag = true;
            }
            if (flag) break;
        }
    }

    int width = 0, res = 0;
    int max_height = 0;
    for (int i = 0; i <= 365; i++) {
        if (h_max[i] != 0) {
            width++;
            max_height = max(h_max[i], max_height);
        }
        else {
            res += max_height * width;
            max_height = 0; width = 0;
        }
    }
    res += max_height * width;
    cout << res << endl;
    return 0;
}
