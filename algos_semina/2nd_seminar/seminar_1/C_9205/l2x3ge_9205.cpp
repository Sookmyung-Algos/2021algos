#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void dfs(int a);

vector<int> list[101];
bool visit[101] = { false, };

int main() {
	int t;
	cin >> t;
	
	for (int i = 0;i < t;i++) {
		//init
		for (int k = 0;k < 101;k++) {
			visit[k] = false;
			list[k].clear();
		}
		//입력
		int n;
		cin >> n;
		vector<pair<int, int>> beer(n+2);
		for (int j = 0;j < n+2;j++) {
			cin >> beer[j].first >> beer[j].second;
		}
		//간선 만들기
		for (int x = 0;x < n + 2;x++) {
			for (int y = 0;y < n + 2;y++) {
				int distance = abs(beer[x].first - beer[y].first) + abs(beer[x].second - beer[y].second);
				if (distance <= 1000) {
					list[x].push_back(y);
					list[y].push_back(x);
				}
			}
		}
		dfs(0);
		if (visit[n + 1] == true)
			cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}

void dfs(int a) {
	visit[a] = true;
	for (int i = 0;i < list[a].size();i++) {
		int next = list[a][i];
		if (visit[next] == false) {
			dfs(next);
		}
	}
}
