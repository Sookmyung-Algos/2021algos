#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;

bool visited[100][100] = { false, };

int dy[6] = { +1, +1, -1, -1, -1, +1 };
int dx[6] = { 0, +1, +1,  0, -1, -1 };
//방향--------UU  UR  DR  DD  DL  UL
int direction[6] = { 1,2,3,4,5,6 };

int resultCnt = 0;

void dfs(int y, int x, int dir, int cnt);

int main() {
	cin >> n;

	//처음 개미는 북쪽으로 올라왔다
	visited[49][50] = true;
	//start
	dfs(50, 50, 0, 0);

	cout << resultCnt;
}

void dfs(int y, int x, int dir, int cnt) {
	//서클이 생기고 조건에 맞으면 result++
	if (visited[y][x]) {
		if (cnt == n) { 
			resultCnt++;
			return;
		}
		//조건에 안맞으면 그냥 멈추기
		else return;
	}
	//조건에 안맞으면 그냥 멈추기
	if (cnt >= n) return;


	visited[y][x] = true;

	//다음 방향 두개를 dfs로 돌리기
	int next_right = (dir + 1) % 6;
	int next_left = (dir + 5) % 6;
	dfs(y + dy[next_right], x + dx[next_right], next_right, cnt+1);
	dfs(y + dy[next_left], x + dx[next_left], next_left, cnt+1);

	//n만큼 가서 확인 후 다시 배열 지우기
	visited[y][x] = false;
}
