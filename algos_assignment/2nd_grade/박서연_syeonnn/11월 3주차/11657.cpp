// 11657 타임머신

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

bool cycle;
long long list[501];	// 1번 도시에서 2번 도시, 3번 도시,..., N번 도시로 가는 가장 빠른 시간 저장
vector<pair<int, int>> v[501];	// 도착도시, 이동시간 저장
int N, M;	// 도시 개수, 버스 노선 개수
int A, B, C;	// 버스의 정보 (시작도시, 도착도시, 이동시간)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();	cout.tie();

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
	}

	// 노드 초기 설정
	for (int i = 1; i <= N; i++) {
		list[i] = INF;
	}

	list[1] = 0;	// 시작점 0으로 초기화

	for (int i = 1; i <= N; i++) {	// 한 정점씩 확인
		for (int j = 1; j <= N; j++) {	// 경유지 지정 
			for (int k = 0; k < v[j].size(); k++) {	// 도착지 (경유지가 도착지인 경우 + 나머지 도시들 전부)
				int next = v[j][k].first;	// 다음 도시
				int cost = v[j][k].second;	// 이동 시간

				if (list[j] != INF && list[next] > list[j] + cost) {
					list[next] = list[j] + cost;	// 최단 시간의 경로 갱신
					if (i == N)	// 모든 경로 탐색후에도 갱신된다면
						cycle = true;	// 음의 사이클
				}
			}
		}
	}

	if (cycle)
		cout << -1 << '\n';

	else {
		for (int i = 2; i <= N; i++)
			cout << (list[i] != INF ? list[i] : -1) << '\n';
	}
}
