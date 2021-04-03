#include <iostream>
#include <cstring>
using namespace std;
int per[1001]; // 순열 저장하는 배열
bool visit[1001] = { false, };
int cnt = 0;
void dfs(int n);

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> per[i];
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false) 
				dfs(i);
		}
		cout << cnt << "\n";
		cnt = 0;
		memset(visit, false, sizeof(visit));
	}
}

void dfs(int n) {
	visit[n] = true;
	int next = per[n];
	if (visit[next] == false)
		dfs(next);
	else
		cnt++;
}
