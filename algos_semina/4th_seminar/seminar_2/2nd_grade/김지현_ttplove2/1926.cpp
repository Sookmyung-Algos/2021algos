#include <iostream>
#include <queue>
using namespace std;

int N, M;
int group = 0;
int area = 0, max_area = -1;
int arr[503][503];
bool visit[503][503];
queue <pair<int, int>> q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs()
{
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
					visit[ny][nx] = true;
					area++;
					max_area = max(area, max_area);
					q.push({ ny, nx });
				}
			}
		} 
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == false && arr[i][j] == 1) {
				visit[i][j] = true;
				group++;
				q.push({ i, j });
				area = 0; area++;
				max_area = max(max_area, area);
				bfs();
			}
		}
	}

	if (group == 0) cout << "0\n0\n";
	else cout << group << "\n" << max_area << "\n";
	return 0;
}
