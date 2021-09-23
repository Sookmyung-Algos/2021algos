#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector <int> v;
vector<int> cycled;
bool visited[100001];
bool chk[100001] = { false, };
int ans = 0, cnt = 0,n,t;
void dfs(int n);
void init();
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		init();//ans==n,cnt==0
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout <<ans-cnt << '\n';
	}
	return 0;
}
void dfs(int n) {
	visited[n] = true;//방문여부확인
	int next = v[n];
	/*if (next == n) {
		cycled[cnt++] = n;
	}*/
	if (!visited[next])
		dfs(next);
	//사이클 형성하면 한바퀴 돌면서 사이클에 해당하는 원소 개수 카운트
	if (!chk[next]) {
		cycled[cnt++] = n;
		for (int i = v[n]; i != n; i = v[i]) {
			cycled[cnt++] = i;
			}
	}
	chk[n] = true;
}
void init() {
	v.clear();
	v.resize(n + 1);
	cycled.clear();
	cycled.resize(n + 1);
	memset(visited, false, sizeof(bool)*(n+1));
	memset(chk, false, sizeof(bool)*(n+1));
	ans = n;
	cnt = 0;
}
