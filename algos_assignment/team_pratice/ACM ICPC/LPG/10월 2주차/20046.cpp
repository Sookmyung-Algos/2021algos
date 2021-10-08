#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define pip pair<int, pii>

int n, m, arr[1001][1001], visited[1001][1001];
int d[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    int ans = -1;

   cin >> n >> m;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         cin >> arr[i][j];
      }
   }

   //시작점, 끝점이 -1이면 -1출력하고 끝냄.
   if (arr[1][1] == -1 || arr[n][m] == -1) {
      cout << -1 << '\n';
      return 0;
   }

   //작은 값이 우선되도록 하는 pq 만들기
    priority_queue<pip, vector<pip>, greater<pip> > pq;
    pq.push(pip(arr[1][1], pii(1, 1)));

    while (!pq.empty()) {
        pip top = pq.top();
        pq.pop();

        int v = top.first, x = top.second.first, y = top.second.second;

        if (x == n && y == m) {
            ans = v; //비용 합
            break;
        }

        if (visited[x][y]) //방문했으면 건너뛰기
            continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0], ny = y + d[i][1];

            if (nx > n || ny > m || nx <= 0 || ny <= 0)continue; // 범위 넘어가는 경우
            if (arr[nx][ny] == -1)continue; // 다리 공사 못하는 경우
            if (visited[nx][ny])continue;   // 이미 방문한 경우

            pq.push(pip(v + arr[nx][ny], pii(nx, ny))); //위의 경우에 다 해당하지 않으면, pq에 비용 합과, 위치 넣기
        }

        visited[x][y] = 1;
    }

    cout << ans << '\n';

}
