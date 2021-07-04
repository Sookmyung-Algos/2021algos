#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m; //n행 m열, 3 이상 300 이하
int map[300][300]; //melt
int cmap[300][300]; //solution
bool visited [300][300];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int a, int b);
int melt(int x, int y);
void solution();

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)	cin >> map[i][j];
	}
  solution();
	return 0;
}
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visited[a][b] = true;

	while (q.empty() == 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int newx = x + dx[i];
			int newy = y + dy[i];

			if (newx >= 0 && newy >= 0 && newx < n && newy < m){
				if (visited[newx][newy] == false && map[newx][newy] != 0){
					visited[newx][newy] = true;
					q.push(make_pair(newx, newy));
				}
			}
		}
	}
}
int melt(int x, int y){
    int cnt = 0;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (map[nx][ny] == 0) cnt++;
    }
    return cnt;
}
void solution(){
    int year = 0;
    while (1){
        int landcnt = 0;
        memset(visited, false, sizeof(visited)); //메모리 초기화: 배열 visited를 false로
        memset(cmap, 0, sizeof(cmap)); //메모리 초기화: 배열 camp을 0으로

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (map[i][j] != 0 && visited[i][j] == false){
                    landcnt++;
                    bfs(i, j);
                }
            }
        }
        if (landcnt >= 2) {
            cout << year << endl;
            break;
        }
        if (landcnt == 0) {
            cout << 0 << endl;
            break;
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (map[i][j] != 0){
                    cmap[i][j] = map[i][j] - melt(i, j);
                    if (cmap[i][j] < 0) cmap[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) map[i][j] = cmap[i][j];
        }
        year++;
    }
}
