// 22352 항체 인식(Gold 5)
#include <iostream>
#include <vector>
#include <queue>
#define MAX 31
using namespace std;

int n, m;  // n: 세로, m: 가로
int before[MAX][MAX];
int after[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

// before에 주사한 결과가 after와 같은지 비교
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> before[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> after[i][j];
		}
	}

	bool hasBeenVac = false;  // 주사된 적 있는지

	for (int i = 0; i < n; i++) {
		if (hasBeenVac)
			break;
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || before[i][j] == after[i][j])
				continue;
			if (before[i][j] != after[i][j])
				hasBeenVac = true;

			int befV = before[i][j];
			int aftV = after[i][j];
			before[i][j] = after[i][j];
			visited[i][j] = true;

			// bfs
			queue<pair<int, int>> q;  // 행, 열 저장
			q.push({ i,j });
			while (!q.empty()) {
				pair<int, int> p = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nextR = p.first + dx[k];
					int nextC = p.second + dy[k];
					if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m || visited[nextR][nextC])
						continue;
					if (before[nextR][nextC] == befV) {
						before[nextR][nextC] = aftV;
						q.push({ nextR,nextC });
						visited[nextR][nextC] = true;
					}
				}
			}
		}
	}

	// 바뀐 before와 입력받은 after 비교
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (before[i][j] != after[i][j]) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}
