// 1068: 트리 (Gold 5)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, erase, cnt;
vector<vector<int>> tree;
vector<int> v;
vector<bool> deleted;

// bfs 통해 해당 노드와 노드의 자식들 삭제
void bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        deleted[cur] = true;
        for (int i = 0; i < tree[cur].size(); i++) {
            int next = tree[cur][i];
            if (deleted[next])
                continue;
            q.push(next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    deleted.resize(n);

    for (int i = 0; i < n; i++)
        tree.push_back(v);
    int p;
    for (int i = 0; i < n; i++) {  // i는 노드 번호
        cin >> p;
        if (p == -1)  // 루트노드인 경우
            continue;
        else {
            tree[p].push_back(i);
        }
    }
    cin >> erase;
    bfs(erase);

    // 리프 노드 개수
    for (int i = 0; i < n; i++) {
        if (!deleted[i]) {  // 노드 i가 삭제 되지 않았다면
            int j = -1;
            for (j = 0; j < tree[i].size(); j++) {  // i의 자식들 탐색, j는 삭제된 자식 수
                if (!deleted[tree[i][j]])  // 자식노드가 삭제 되지 않았다면 
                    break;  // 끝
            }
            if (j == tree[i].size())  // j와 i의 자식노드의 수가 같다면 i가 리프노드이다.
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}
