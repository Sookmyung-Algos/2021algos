#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

const int MAX = 100 + 2;

int n;
vector<int> arr[MAX];
bool visited[MAX];

int distance(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void DFS(int node) {
	visited[node] = true;

	for (int i = 0; i < arr[node].size(); i++) {
		int next = arr[node][i];
		if (visited[next] == false) DFS(next);
	}
}

int main() {
	int t, x, y;
	cin >> t;

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < MAX; j++)
			arr[j].clear();
		memset(visited, false, sizeof(visited));

		cin >> n;
		vector <pair<int, int>> v;

		for (int j = 0; j < n + 2; j++) {
			cin >> y >> x;
			v.push_back(make_pair(y, x));
		}

		for (int j = 0; j < n + 2; j++)
			for (int k = j + 1; k < n + 2; k++)
				if (distance(v[j], v[k]) <= 50 * 20) {
					arr[j].push_back(k);
					arr[k].push_back(j);
				}
		DFS(0);

		if (visited[n + 1])
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
}
