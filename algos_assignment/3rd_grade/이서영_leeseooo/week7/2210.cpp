#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
int arr[5][5];
set<int>s;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;
void solve(int x,int y, int size,int num) {
	if (size == 6) {
		s.insert(num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
			solve(nx, ny, size + 1, num * 10 + arr[nx][ny]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			solve(i, j, 1, arr[i][j]);
		}
	}
	cout << s.size();
}
