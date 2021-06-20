#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
string arr[25];
bool vi[25][25] = { false, };
int N, cnt;
vector <int> ans;

void dfs(int i, int j) {

	vi[i][j] = true;
	cnt++;
	int k;

	for (k = 0; k < 4; k++) {
		int newY = i + dy[k];
		int newX = j + dx[k];

		if (0 <= newX && newX < N && 0 <= newY && newY < N)
			if (arr[newY][newX] == '1' && !vi[newY][newX]) dfs(newY, newX);
	}
}

int main() {
	int i, j;

	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (arr[i][j] == '1' && !vi[i][j]) {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (i = 0; i < ans.size(); i++) cout << ans[i] << endl;

	return 0;
}
