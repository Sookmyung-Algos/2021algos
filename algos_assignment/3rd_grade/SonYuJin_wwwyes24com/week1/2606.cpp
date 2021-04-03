#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
bool visit[101];
vector<int> virus[101];
void dfs(int n);

int main() {
	int n, pair;

	cin >> n;
	cin >> pair;
	while (pair--) {
		int a, b;
		cin >> a >> b;
		virus[a].push_back(b);
		virus[b].push_back(a);
	}
	dfs(1);
	cout << cnt;
}

void dfs(int n) {
	visit[n] = true;
	if (n != 1)
		cnt++;
	for (int i = 0; i < virus[n].size(); i++) { // n의 자손들
		int next = virus[n][i];
		if (!visit[next])
			dfs(next);
	}
}
