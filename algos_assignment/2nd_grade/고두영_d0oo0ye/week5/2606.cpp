#include <iostream>
#include <vector>
using namespace std;

int number, n;
int virus = 0;
int c[101];
vector<int> a[101];

int dfs(int x) {
	if (!c[x]) {
		c[x] = true;
		virus++;

		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			dfs(y);
		}
	}
	return virus;
}

int main(void) {
	cin >> number;

	for (int i = 1; i <= number; i++) {
		c[i] = 0;
	}

	cin >> n;
	int s, t;

	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		a[s].push_back(t);
		a[t].push_back(s);
	}

	cout << dfs(1) - 1;
	return 0;
}
