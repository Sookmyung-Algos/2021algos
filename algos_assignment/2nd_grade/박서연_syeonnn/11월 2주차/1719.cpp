// 1719 택배

#include <iostream> 
#include <algorithm> 
using namespace std;

#define INF 1e9 

int N, M; 
int grp[201][201], ans[201][201];

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 

	cin >> N >> M; 

	// 경로표 초기 설정
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= N; j++) { 
			if (i == j) 
				grp[i][j] = 0;
			else 
				grp[i][j] = INF;
		} 
	} 

	for (int i = 0; i < M; i++) { 
		int from, to, cost;
		cin >> from >> to >> cost;

		// 간선과 가중치 저장
		grp[from][to] = cost;
		grp[to][from] = cost;
		// 거칠 필요없이 바로 이동가능한 경우
		ans[from][to] = to;
		ans[to][from] = from;
	} 
	
	// 최단 경로 갱신
	for (int k = 1; k <= N; k++) { 
		for (int i = 1; i <= N; i++) { 
			for (int j = 1; j <= N; j++) { 
				// i에서 k를 걸쳐 j를 가는 경우가 더 짧을 때
				if (grp[i][j] > grp[i][k] + grp[k][j]) {
					grp[i][j] = grp[i][k] + grp[k][j];
					ans[i][j] = ans[i][k];
				} 
			} 
		} 
	} 

	// 경로표 출력
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= N;j++) { 
			if (ans[i][j] == 0)
				cout << "- "; 
			else 
				cout << ans[i][j]<< ' ' ;
		} 
		cout << '\n'; 
	} 

	return 0; 
}
