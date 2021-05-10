#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char mapp[1010][1010];
int visited[1010][1010] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, m, cycle_num = 1, answer = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char direction;

			cin >> direction;

			mapp[i][j] = direction;

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) {
				continue;
			}

			int x = j;
			int y = i;

			while (!visited[y][x]) {
				visited[y][x] = cycle_num;
				switch (mapp[y][x]) {
					case 'N':
						y -= 1;
						break;
					case 'W':
						x -= 1;
						break;
					case 'E':
						x += 1;
						break;
					case 'S':
						y += 1;
						break;
				}
			}
			
			if (cycle_num == visited[y][x]) {
				answer++;
			}
			cycle_num++;

		}
	}
	cout << answer;
}
