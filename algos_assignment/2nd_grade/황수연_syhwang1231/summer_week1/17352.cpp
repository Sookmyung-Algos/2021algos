// 17352 여러분의 다리가 되어 드리겠습니다!(Gold 5)
#include <iostream>
#include <vector>
#include <queue>
#define MAX 300001
using namespace std;

int n;
vector<int> path[MAX];
bool ableToReach[MAX];	// 1번 섬(기준)에서 도달할 수 있는 마을

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;	// 섬의 개수 입력

	for (int i = 0; i < n - 2; i++) {	// 왕복이 가능한 섬들
		int k,m;
		cin >> k >> m;
		path[k].push_back(m);  // 왕복 가능
		path[m].push_back(k);
	}
	
	ableToReach[1] = true;	// 1번 섬에서 1번섬은 왕복 가능
    
    // bfs
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int path_index = q.front();		// path_index에는 v의 front 값 저장, 즉 path_index섬과 연결된 섬 찾기 위함
		q.pop();

		for (int i = 0; i < path[path_index].size(); i++) {		// path_index번째 섬과 연결된 섬의 개수동안 반복, 그 섬들은 1과 연결 가능
			int nextIsland = path[path_index][i];		// next에 path_index번 섬과 연결된 섬의 번호 저장

			if (!ableToReach[nextIsland]) {		// reach배열에서 next번째 값이 0이면, 즉 1번과 연결되지 않았다면
				ableToReach[nextIsland] = true;	// 1(왕복가능) 상태로 변경
				q.push(nextIsland);
			}
		}
	}

	int connect;	// 1번과 연결해야 할 섬 번호 connect
	for (int i = 1; i <= n; i++) {
		if (!ableToReach[i]) {	// reach 배열에서 원소가 0인(왕복불가능한) 값을 찾으면
			connect = i;	// connect에 인덱스 번호 저장
			break;
		}
	}

	cout << 1 << " " << connect;
	return 0;
}
