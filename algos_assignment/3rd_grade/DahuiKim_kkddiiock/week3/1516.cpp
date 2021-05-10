#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
int ind[501] = { 0, };
int time[501] = { 0, };
int result[501] = { 0, };
vector<int>v[501];
void topology();
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> time[i];
		while (1) {
			cin >> tmp;
			if (tmp == -1)break;
			v[tmp].push_back(i);
			ind[i]++;
		}
	}
	topology();
	for (int i = 1; i <= n; i++)
		cout << result[i] << "\n";
	return 0;
}
void topology() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)q.push(i);
		result[i] = time[i];
	}
	for (int i = 1; i <= n; i++) {
		int node = q.front();
		q.pop();
		for (int j = 0; j < v[node].size(); j++) {
			int next = v[node][j];
			ind[next]--;
			result[next] = max(result[next], result[node] + time[next]);
			if (ind[next] == 0)q.push(next);
		}
	}
}
