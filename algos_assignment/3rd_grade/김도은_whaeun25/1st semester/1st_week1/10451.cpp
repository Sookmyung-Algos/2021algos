#include<iostream>
#include<vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;

	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		
		int n, count = 0;

		vector<int>cycle;
		vector<int>visited;
		
		cin >> n;
		cycle.push_back(0);
		visited.push_back(1);

		for (int i = 0; i < n; i++) {
			int a;

			cin >> a;

			cycle.push_back(a);
			visited.push_back(0);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				count++;
				
				int next = cycle[i];
				while (!(visited[next])) {
					visited[next] = 1;
					next = cycle[next];
				}

			}
		}

		cout << count << "\n";

	}

}
