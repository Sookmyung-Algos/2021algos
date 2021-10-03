#include <iostream>
#include <algorithm>
using namespace std;
int n;
int num[15];
int lotto[6];
void dfs(int node, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
			cout << lotto[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = node; i < n; i++) {
			lotto[cnt] = num[i];
			dfs(i + 1, cnt + 1);
		}
	}
}

int main() {
	while (1) {	
		cin >> n;
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		dfs(0, 0);
		cout << "\n";
	}
}
