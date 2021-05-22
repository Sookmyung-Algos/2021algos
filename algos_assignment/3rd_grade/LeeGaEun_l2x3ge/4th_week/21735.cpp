#include <iostream> 
#include<algorithm>
using namespace std;

void dfs(int time, int idx, int snow);

int n, m, a, answer = 0;
int v[1000111] = { 0, };

int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1;i < n+1;i++) {
		cin >> v[i];
	}
	dfs(0, 0, 1);

	cout << answer;
}

void dfs(int time, int idx, int snow) {
	//가장 큰 경우를 찾는다
	answer = max(answer,snow);
	if (time == m || idx > n)
		return;
	//한 칸 전진
	dfs(time + 1, idx + 1, snow + v[idx + 1]);
	//두 칸 전진
	dfs(time + 1, idx + 2, snow / 2 + v[idx + 2]);
}
