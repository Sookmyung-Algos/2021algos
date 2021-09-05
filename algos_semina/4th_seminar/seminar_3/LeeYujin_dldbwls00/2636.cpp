#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n, m;
int arr[101][101];
int visit[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>>q;
void bfs() {
    q.push({ 0,0 });
    visit[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny]) {
                if (arr[nx][ny] == 0) {
                    q.push({ nx,ny });
                }
                else if (arr[nx][ny] == 1) {//치즈
                    arr[nx][ny] = 0;
                }
                visit[nx][ny] = true;
            }
        }
    }
}
bool isAllCheezeMelted() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) return false;
        }
    }
    return true;
}
int countCheeze() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int meltTime = 0;
    int cheezeCnt = 0;
    while (1) {
        if (isAllCheezeMelted()) break;
        memset(visit, false, sizeof(visit));
        cheezeCnt = countCheeze();
        bfs();
        meltTime++;
    }
    cout << meltTime << "\n" << cheezeCnt;
}
