#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
void dfs(int node);
void init();
int cnt = 0;
int v[100001];
bool visit[100001] = { false, };
bool finish[100001] = { false, };
int cycle[100001];
int main() {
	int T,N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= N; i++) {
			if (!visit[i])
				dfs(i);
		}
		cout << N-cnt << "\n";//사이클 발생=>팀 짜여짐이므로 전체N-cnt
		init();
	}
}
void dfs(int node) {
	visit[node] = true;
	int next = v[node];
	if (!visit[next])
		dfs(next);
	else {
		if (!finish[next]) {
			for (int i = next; i != node; i = v[i]) {
				cnt++; //연결된 학생들 카운트
			}
			cnt++;// i=v[i]로 인해 자기 자신일때 탈출했기 때문에 한번더 카운트
		}
	}
	finish[node] = true;
}
void init() {
	cnt = 0;
	memset(v, 100001, sizeof(v));
	memset(visit, false, sizeof(visit));
	memset(finish, false, sizeof(finish));
}
