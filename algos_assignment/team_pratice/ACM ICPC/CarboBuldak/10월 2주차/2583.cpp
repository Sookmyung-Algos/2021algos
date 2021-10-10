// 2583 (실버1) 영역 구하기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101];
bool visited[101][101];
// x,y 좌표 순서 조심하기
vector<int> ans;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m, k;    //  가로n,세로m 모눈종이, k개 직사각형 그림
int cnt;    // 직사각형에 의해 나눠진 각 공간의 크기

void dfs(int y, int x) {
    visited[y][x] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if ((nx >= 0 && nx < n && ny >= 0 && ny < m) && (arr[ny][nx] == 0 && !visited[ny][nx]))
            dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int sx, sy, ex, ey; // 각 직사각형의 왼쪽 아래 꼭짓점, 오른쪽 위 꼭짓점 좌표
    cin >> m >> n >> k;

    while(k--)
    {
        cin >> sx >> sy >> ex >> ey;
        for (int i = sy; i < ey; i++) {
            for (int j = sx; j < ex; j++) {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0 && !visited[i][j]) { // 직사각형에 의해 채워지지 않은 공간이라면
                cnt = 0;    // 다음 공간의 크기 측정을 위해 0으로 초기화 반복
                dfs(i, j);  // dfs함수를 통해 해당 공간의 크기 리턴
                ans.push_back(cnt);
            }
        }
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());   // 오름차순 정렬

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
