#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

string board[627];
int check[27][27];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int total = 0;
int adressTotal = 0;
int arr[1000];
int idx = 0;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	queue<pair<int, int>> Q;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];

	for (int i = 0; i < N; i++) {  //이중 for문과 bfs를 이용하여 구현
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '1' && check[i][j] == 0) {
				total++;
				check[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty()) {
					adressTotal++;
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (board[nx][ny] == '0' || check[nx][ny] == 1) continue;
						check[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			}
			arr[idx++] = adressTotal;
			adressTotal = 0;
		}
	}
	if (total == 0) {
		cout << 0 << "\n" << 0;
		return 0;
	}
	else {
		cout << total << "\n";
		sort(arr, arr + 1000);
		for (auto n : arr)
			if (n != 0) cout << n << "\n";
	}
}
