#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int parent[500001] = { 0, };
int Find(int x) {
	if (parent[x] == x) {//부모같을때
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}
int Union(int x,int y) {
	x = Find(x);
	y = Find(y);//부모찾기
	if (x != y) {
		parent[y] = x;
		return -1;
	}
	else {
		//부모가 같음 == 사이클생김
		return 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (Union(a, b) == 1) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}
