#include<iostream>
#include<queue>
using namespace std;
int n, start, finish, m, map[101][101], dis[101]; // 전체 사람 수, 촌수 계산할 두 사람, 관계 수, 인접 행렬 그래프, 촌수 계산용 배열
int main() {
    cin >> n >> start >> finish >> m;
    for (int i = 0; i < m; i++) {
        int x = 0, y = 0;
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }

    queue<int> q;
    q.push(start);
    while (!q.empty()) {  // 큐에 값이 있을경우 (=방문하지 않은 노드가 있는 경우)
        int now = q.front(); q.pop();
        for (int i = 1; i <= n; i++) {
            if (map[now][i] == 0 || dis[i] != 0) // 방문하지 않았다면
                continue; // 메모리초과 해결
            dis[i] = dis[now] + 1;
            q.push(i);
        }
    }
    cout << (dis[finish] == 0 ? -1 : dis[finish]) << endl;
    return 0;
}




