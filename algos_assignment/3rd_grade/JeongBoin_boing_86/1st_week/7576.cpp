#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m, n;
int ans = 0;
int box[1001][1001];
int tarr[1001][1001] = { 0, };
int prow[4] = { -1, 0, 1, 0 }; //시계방향
int pcol[4] = { 0, 1, 0, -1 };
queue <pair<int, int>> q;

void fuct() {
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();

		int x2, y2;
		for (int i = 0; i < 4; i++) {
			x2 = x1 + prow[i];
			y2 = y1 + pcol[i];

			if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && box[x2][y2] == 0) {
				//[x2][y2]가 박스안에 있고 0이라면
				box[x2][y2] = 1;
				q.push({ x2, y2 });
				tarr[x2][y2] = tarr[x1][y1] + 1;
			}
		}

	}
}

int main() {

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}
	//cout << "입력완료";

	fuct();
	//cout << "fuct 완료";

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << box[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) { //하나라도 익지 않으면
				
				cout << -1;
				return 0;
			}
			if (ans < tarr[i][j]) {
				ans = tarr[i][j];
			}
		}
	}

	cout << ans;
  
  return 0;
}
