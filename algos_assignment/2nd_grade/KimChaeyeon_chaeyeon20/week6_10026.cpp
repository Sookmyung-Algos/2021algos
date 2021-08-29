#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm> 
#include <cstring>
#include <queue>
#define MAX 104
using namespace std;
int n;
char arr[MAX][MAX];
char arr2[MAX][MAX];
int used[MAX][MAX];
int color[3];
struct Node {
	int y, x;
};
queue <Node> qu;
void bfs(int y, int x) {
	char co = arr[y][x];
	used[y][x] = 1;
	if (arr[y][x] == 'R') color[0]++;   //빨
	else if (arr[y][x] == 'G') color[1]++;  //초
	else color[2]++;

	int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
	qu.push({ y,x });

	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dy = dir[i][0] + now.y;
			int dx = dir[i][1] + now.x;

			if (dy < 0 || dx < 0 || dy >= n || dx >= n) continue;
			if (used[dy][dx] == 1) continue;
			if (arr[dy][dx] != co) continue;

			used[dy][dx] = 1;
			qu.push({ dy,dx });
		}
	}

}
void bfs2(int y, int x) {
	char co = arr2[y][x];
	used[y][x] = 1;
	if (arr2[y][x] == 'R') color[0]++;   //빨
	else if (arr2[y][x] == 'G') color[1]++;  //초
	else color[2]++;

	int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
	qu.push({ y,x });

	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dy = dir[i][0] + now.y;
			int dx = dir[i][1] + now.x;

			if (dy < 0 || dx < 0 || dy >= n || dx >= n) continue;
			if (used[dy][dx] == 1) continue;
			if (arr2[dy][dx] != co) continue;

			used[dy][dx] = 1;
			qu.push({ dy,dx });
		}
	}

}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used[i][j] == 0) bfs(i, j);

		}
	}
	int nojuk = 0;
	int juk = 0;
	for (int i = 0; i < 3; i++) {
		nojuk += color[i];
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'R') arr2[i][j] = 'G';
			else arr2[i][j] = arr[i][j];
		}
	}
	memset(used, 0, sizeof(used));
	memset(color, 0, sizeof(color));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used[i][j] == 0) bfs2(i, j);

		}
	}
	juk = color[2] + color[1];
	cout << nojuk << " " << juk;
	return 0;

}
