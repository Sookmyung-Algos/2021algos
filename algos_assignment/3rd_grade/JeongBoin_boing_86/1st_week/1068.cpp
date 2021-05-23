//5월 24일 2학년 스터디 문제 풀이
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v[51];

int n, d_node, r_node;
int ans = 0;

void solve(int x) {
	if (d_node == x) {
		return;
	}

	int t_size = v[x].size();

	if (t_size == 0) {
		ans++;
		return;
	}

	if (t_size == 1) {
		if (v[x][0] == d_node) {
			ans++;
		}
	}

	else {
		for (int i = 0; i < t_size; i++) {
			solve(v[x][i]);
		}
	}
}

int main() {
	int a;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == -1) {
			r_node = i;
		}
		else {
			v[a].push_back(i);
		}

	}
	cin >> d_node;
	solve(r_node);
	cout << ans;
}
