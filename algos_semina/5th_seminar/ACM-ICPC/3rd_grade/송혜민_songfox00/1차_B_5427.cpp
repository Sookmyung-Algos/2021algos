#include <iostream>
#include<queue>
#include<cstring>

using namespace std;

char arr[1001][1001];
bool visit[1001][1001];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
vector<pair<int, int>>fire;
int sx, sy, h, w, res;

int bfs() {
	int cnt = 0;
	queue<pair<int,int>>q;
	queue<pair<int, int>>fire2;
	q.push({ sx,sy });
	visit[sx][sy] = true;	//넣어도 안넣어도 괜찮음

	for (int i = 0; i < fire.size(); i++) {
		fire2.push(fire[i]);
	}

	while (!q.empty()) {
		int firesize = fire2.size();
		for (int i = 0; i < firesize; i++) {	//불
			int x = fire2.front().first;
			int y = fire2.front().second;
			fire2.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
					if (arr[nx][ny] == '.') {
						arr[nx][ny] = '*';
						fire2.push({ nx,ny });
					}
				}
			}
		}

		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {	//사람
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 || x == h - 1 || y == 0 || y == w - 1) { //가장자리면 바로 나갈 수 있음
				return cnt+1;
			}

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visit[nx][ny] && arr[nx][ny] != '*' && arr[nx][ny] != '#') {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> w >> h;

		fire.clear();
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') {
					sx = i, sy = j;
				}
				if (arr[i][j] == '*') {
					fire.push_back({ i,j });
				}
			}
		}

		res = bfs();

		if (res!=-1)
			cout << res << '\n';
		else
			cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}