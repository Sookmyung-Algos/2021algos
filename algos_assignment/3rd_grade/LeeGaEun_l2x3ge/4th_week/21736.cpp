#include <iostream> 
#include <queue>
#include<algorithm>
using namespace std;

int n, m, start_x, start_y;
int people = 0;
void bfs();
char v[1001][1001];
bool visited[1001][1001] = { false, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> v[i][j];
			if (v[i][j] == 'I') {
				start_x = i;
				start_y = j;
			}
		}
	}
	bfs();
	if (people == 0)
		cout << "TT";
	else cout << people;
}

void bfs() {
	queue <pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && (v[next_x][next_y] != 'X') && visited[next_x][next_y] ==false) {
				visited[next_x][next_y] = true;
				q.push(make_pair(next_x, next_y));
				//------사람----------
				if (v[next_x][next_y] == 'P') {
					people++;
				}
			}
		}
	}
}
