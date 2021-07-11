#include <iostream>
#include <queue>
using namespace std;

int n, m;
int lab[10][10];
int org[10][10];
int mv_x[4] = { -1,1,0,0 };
int mv_y[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;

int bfs() {
	int safe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			lab[i][j] = org[i][j];
			if (lab[i][j] == 2)
				q.push({ i,j });
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) { 
			int nextX = x + mv_x[i];
			int nextY = y + mv_y[i];
			
			if (lab[nextX][nextY] == 0 && nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
				lab[nextX][nextY] = 2;
				q.push({ nextX,nextY });
			}
		}
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0)
				safe++;
		}
	}
	return safe;
}

int main() {
	int max = 0, safety;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> org[i][j];
		}
	}

	for (int a1 = 0; a1 < n; a1++) { // 벽 1(a1,b1)
		for (int b1 = 0; b1 < m; b1++) {
			for (int a2 = 0; a2 < n; a2++) { // 벽 2(a2,b2)
				for (int b2 = 0; b2 < m; b2++) {
					for (int a3 = 0; a3 < n; a3++) { // 벽 3(a3,b3)
						for (int b3 = 0; b3 < m; b3++) {
							if (org[a1][b1] || org[a2][b2] || org[a3][b3]) // 벽 놓는 위치가 빈칸이어야 함
								continue;
							if ((a1 == a2 && b1 == b2) || (a1 == a3 && b1 == b3) || (a3 == a2 && b3 == b2)) // 벽 3개가 모두 달라야 함
								continue;
							
							org[a1][b1] = 1; // 벽 놓기
							org[a2][b2] = 1;
							org[a3][b3] = 1;
							
							safety = bfs();
							
							if (max < safety)
								max = safety;
							
							org[a1][b1] = 0; // 벽 원상태로
							org[a2][b2] = 0;
							org[a3][b3] = 0;
						}
					}
				}
			}
		}
	}
	cout << max;
}
