#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int list[1002], check[1002];
int cycle = 0;
void dfs(int x) {
	check[x] = 1;
	if (check[list[x]] == 0)
		dfs(list[x]);
	else
		cycle++;
}
int main() {
	int t, n;
	cin >> t;

	for (int z = 0; z < t; z++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> list[i];
		}
		for (int k = 1; k <= n; k++) {
			if (check[k] == 0)
				dfs(k);
		}
		cout << cycle << '\n';
		cycle = 0;
		for (int k = 1; k <= n; k++) {
			list[k] = 0;
			check[k] = 0;
		}
	}
}
