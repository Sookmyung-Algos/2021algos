#define _CRT_SECURE_NO_WARNINGS
#define MAX 25

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[MAX][MAX] = { 0, };
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
bool isVisited[MAX][MAX] = { false, };
int numOfHome;
vector<int> homes;

void dfs(int fromX, int fromY);

int main(void) {
	cin >> n;  // 지도의 크기 입력
	for (int i = 0; i < n; i++) {  // 지도 정보 입력
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !isVisited[i][j]) {
				numOfHome = 0;  // 하나의 단지 안에 있는 집의 수 초기화
				dfs(i, j);
				homes.push_back(numOfHome);
			}
		}
	}
	sort(homes.begin(), homes.end());  // 단지 값들 오름차순 정렬

	cout << homes.size() << "\n";  // 단지 개수 
	for (int i = 0; i < homes.size(); i++)  // 하나의 단지에 들어있는 집 수
		cout << homes[i] << "\n";

	return 0;
}

void dfs(int fromX, int fromY) {
	isVisited[fromX][fromY] = true;  // 방문 표시
	numOfHome++;

	for (int i = 0; i < 4; i++) {
		int nX = fromX + moveX[i];
		int nY = fromY + moveY[i];
		
		if (nX >= 0 && nX < n && nY >= 0 && nY < n) {  // 유효한 좌표 값이라면
			if (map[nX][nY] == 1 && !isVisited[nX][nY])  // 이동할 수 있고 방문하지 않은 좌표라면
				dfs(nX, nY);  // dfs 호출
		}
	}
}
