#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int, int>> q;
int n, ans = 0;
int a[16];

bool chk(int level) {  
	for (int i = 0; i < level; i++) {  
		if (a[i] == a[level] || (level - i) == abs(a[level] - a[i])) //세로나 대각선에 위치하면 x
			return false;
	}
	return true;
}

void queen(int level) {
	if (level == n) {  //퀸을 다 놓았다면
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {  
		a[level] = i;
		if (chk(level)) //현재 위치에 놓을 수 있으면
			queen(level + 1);
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	queen(0);
	cout << ans;
}
