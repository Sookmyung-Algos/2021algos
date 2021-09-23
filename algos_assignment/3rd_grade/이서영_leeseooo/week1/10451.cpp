#include <iostream>
#include<queue>
#include<cstring>
#include <algorithm>
using namespace std;
void dfs(int node);
int cnt = 0;
int v[1001];
bool visit[1001];
bool finish[1001];
int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) dfs(i);
		}
		cout << cnt << "\n";
		//initializing
		cnt = 0; 
		memset(v, 0, sizeof(v));
		memset(visit,false,sizeof(visit));
		memset(finish, false,sizeof(finish));
	}
}
void dfs(int node) {
	visit[node] = true;
	int next = v[node];
	if (!visit[next])
		dfs(next);
	else if (!finish[next])//다 방문했는데! 끝나지 않았다면 사이클 발생
		cnt++;
	finish[node] = true;
}
