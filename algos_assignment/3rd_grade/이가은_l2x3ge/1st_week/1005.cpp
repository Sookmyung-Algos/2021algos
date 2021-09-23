#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

void topology();
void init();
vector<int> v[1001];
int ind[1001] = { 0, };
int time[1001] = { 0, };
int result_time[1001] = { 0, };
int T, N, K, W;

int main() {
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1;i <= N;i++) {
			cin >> time[i];
		}
		for (int i = 1;i <= K;i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			ind[b]++;
		}
		cin >> W;
		topology();
		init();
	}
}
void topology() {
	queue<int> q;
	//indegree가 0이면 queue에 넣음
	for (int i = 1;i <= N;i++) {
		if (ind[i] == 0) q.push(i);
		result_time[i] = time[i];
	}

	for (int i = 1;i <= N;i++) {
		int node = q.front();
		q.pop();
		for (int j = 0;j < v[node].size();j++) {
			int next = v[node][j];
			ind[next]--;
			result_time[next] = max(result_time[next], result_time[node] + time[next]);
			if (ind[next] == 0) {
				q.push(next);
			}
		}
	}

	cout << result_time[W] << "\n";
}
void init() {
	memset(ind, 0, 1001);
	memset(time, 0, 1001);
	memset(result_time, 0, 1001);
	for (int i = 0; i < 1001; i++) v[i].clear();
}
