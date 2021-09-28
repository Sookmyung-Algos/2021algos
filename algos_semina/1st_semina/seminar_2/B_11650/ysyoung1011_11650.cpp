#include <iostream>
#include <vector>
using namespace std;

vector<int> v[300001];
bool visit[300001] = { false, };
vector<int> a1, a2;

void dfs(int x) {

	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int node = v[x][i];
		if (!visit[node]) {
			//cout << "x: " << x << "next: " << node << endl;
			dfs(node);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cout << "1 " << i << '\n';
			break;
		}
	}
	return 0;
}
