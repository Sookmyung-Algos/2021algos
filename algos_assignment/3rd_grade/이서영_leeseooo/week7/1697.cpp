#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
#define MAX 100001
int n, k;
int visit[MAX]; //특정 위치까지 가는 데 걸리는 최소 시간
int solve() {
	queue<int>q;
	q.push(n);//시작점
	visit[n] = 0; //시작점은 0초

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == k)return visit[k];

		if (cur + 1 < MAX && visit[cur + 1] > visit[cur] + 1) {
			visit[cur + 1] = visit[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && visit[cur - 1] > visit[cur] + 1) {
			visit[cur - 1] = visit[cur] + 1;
			q.push(cur - 1);
		}
		if (cur * 2 < MAX && visit[cur * 2] > visit[cur] + 1) {
			visit[cur * 2] = visit[cur] + 1;
			q.push(cur * 2);
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < MAX; i++)visit[i] = 987654321;
	cout << solve();
}
