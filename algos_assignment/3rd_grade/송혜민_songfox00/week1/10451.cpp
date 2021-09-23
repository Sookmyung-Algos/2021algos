#include<iostream>
#include<cstring>

using namespace std;

int v[1001];
bool finish[1001] = { false, };
bool visit[1001] = { false, };
int cnt = 0;

void dfs(int node) {
	visit[node] = true;
	int next = v[node];

	if (!visit[next])
		dfs(next);
	else if (!finish[next])	//사이클이 형성되었다면
		cnt++;

	finish[node] = true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}

		for (int i = 1; i <= n; i++) {
			if (!visit[i])
				dfs(i);
		}
		cout << cnt<<'\n';

		cnt = 0;
		memset(v, 0, 1001);	//배열 비우기
		memset(visit, false, 1001);
		memset(finish, false, 1001);
	}
	
	return 0;
}
