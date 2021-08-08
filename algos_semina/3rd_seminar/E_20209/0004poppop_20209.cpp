#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int N, K;
vector<int> swch[8];    // 스위치들

bool allSame(vector<int>& v) {
    int n = v[0];
    for (int i : v) if (n != i) return false;
    return true;
}

vector<int> press(vector<int>& cube, int n) {
    vector<int> ret = cube; // 큐브들

    for (int i : swch[n]) {
        ret[i - 1] += n + 1;
        ret[i - 1] %= 5;
    }

    return ret;
}

// 최소 횟수=최단 거리 문제
int bfs(vector<int>& init) {
    map<vector<int>, int> m;    // 지점마다의 최단거리 기록위해 map자료구조 사용
    queue<vector<int>> q;

    m[init] = 0;
    q.push(init);

    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        int curDist = m[cur];

        if (allSame(cur)) return curDist;

        for (int i = 0; i < K; i++) {
            vector<int> next = press(cur, i);
            if (m.find(next) == m.end()) {
                m[next] = curDist + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    vector<int> cube(N);
    for (int& i : cube) cin >> i;

    for (int i = 0; i < K; i++) {
        int n; 
        cin >> n;
        swch[i] = vector<int>(n);
        for (int& num : swch[i]) 
            cin >> num;
    }

    cout << bfs(cube);

    return 0;
}
