#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int n, m, a[9];
bool visit[9];

void sol(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == true)
			continue;
		visit[i] = true;
		a[k] = i;
		sol(k + 1);
		visit[i] = false;
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	sol(0);
}
