#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
char arr[1001][1001];
int n, m, cnt, ans;
int c[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j]==0) {
				cnt++;
				int x = i, y = j;
				while (!c[x][y]) { //사이클
					if (arr[x][y] == 'S') { 
						c[x][y] = cnt; 
						x++; 
					}
					else if (arr[x][y] == 'W') {
						c[x][y] = cnt;
						y--; 
					}
					else if (arr[x][y] == 'N') {
						c[x][y] = cnt;
						x--; 
					}
					else if (arr[x][y] == 'E') { 
						c[x][y] = cnt; 
						y++;
					}
				}
				if (c[x][y] == cnt)//종료지점인 c[x][y]가 이번 사이클에 해당하는 cnt인지 확인
					ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
