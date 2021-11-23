#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int parent[1000050];
int num[1000000];
int n, m, money, a, b, ans=0;

int find(int x) {
	if (parent[x] == -1)
		return x;
	else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (num[x] < num[y])
		parent[y] = x;
	else
		parent[x] = y;
}

int isUnion(int x, int y) { //집합인지 확인하는 것 안쓰임
	x = find(x);
	y = find(y);
	if (x == y) return true;
	return false;
}

int main() {
	cin >> n >> m >>money;
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	memset(parent, -1, sizeof(parent));

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (parent[i] == -1) {
			ans += num[i];
		}
	}
	if (ans > money)
		cout << "Oh no" << "\n";
	else
		cout << ans << "\n";
}
