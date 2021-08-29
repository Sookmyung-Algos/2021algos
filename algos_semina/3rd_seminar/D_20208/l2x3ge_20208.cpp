#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void backtracking(int x, int y, int hp, int milk);
vector<pair<int,int>> list;

int arr[11][11];
bool visited[11][11] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m, h;
int hx, hy;
int maxx = 0;

int main()
{
	
	cin >> n >> m >> h;


	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				hx = i;hy = j;
			}
			if (arr[i][j] == 2) {
				list.push_back(make_pair(i, j));
			}
		}
	}
	backtracking(hx,hy,m,0);
	cout << maxx;

	return 0;
}
void backtracking(int x, int y, int hp, int milk) {
	int dis = abs(x - hx) + abs(y - hy);
	if (hp == 0) 
		return;

	if (dis <= hp) {
		if (maxx < milk) maxx = milk;
	}
	
	for (int i = 0;i < list.size();i++) {
		int nx = list[i].first;
		int ny = list[i].second;
		int distance = abs(nx - x) + abs(ny - y);
		if (!visited[nx][ny] && distance <= hp) {
			visited[nx][ny] = true;
			backtracking(nx, ny, hp - distance + h, milk+1);
			visited[nx][ny] = false;
		}
	}
}
