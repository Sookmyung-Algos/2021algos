#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
int n, l, r;
int arr[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[51][51];
bool check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n&&ny < n) {
			int tmp = abs(arr[x][y] - arr[nx][ny]);
			if (tmp >= l && tmp <= r)return true;
		}
	}
	return false;
}
void bfs(int a,int b) {
	queue<pair<int, int>>q;
	queue<pair<int, int>>nq; //배열값 변경을 위한 큐
	int sum = 0;
	int cnt = 0;
	q.push({ a,b });
	nq.push({ a,b }); //처음 국가도 초기화
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		sum += arr[x][y]; cnt++; //탐색한 국가 인구정보 저장
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n&&ny < n && !visit[nx][ny]) {
				int tmp = abs(arr[nx][ny] - arr[x][y]);
				if (tmp >= l && tmp <= r) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					nq.push({ nx,ny });
				}
			}
		}
	}
	int new_people = sum / cnt;
	while (!nq.empty()) {
		int x = nq.front().first;
		int y = nq.front().second;
		nq.pop();
		arr[x][y] = new_people;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	bool flag = true;
	while (flag) {
		memset(visit, false, sizeof(visit));
		flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && check(i,j)) {//방문x, 인구이동 가능여부
					bfs(i, j);
					flag = true;
				}
			}
		}
		if (flag)ans++;
	}
	cout << ans;
}
