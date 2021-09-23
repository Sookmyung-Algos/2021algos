#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
string arr[25];
bool v[25][25] = {false,};
vector<int> ans;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(int i, int j) {
	v[i][j] = true;
	cnt++;

	for (int k = 0; k < 4; k++) {
		int newX = j + dx[k];
		int newY = i + dy[k];

		if (0 <= newX && newX < n && 0 <= newY && newY < n)
			if (arr[newY][newX] == '1' && !v[newY][newX]) dfs(newY, newX);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '1' && !v[i][j]) {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}
