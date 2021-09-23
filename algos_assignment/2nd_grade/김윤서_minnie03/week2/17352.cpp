#include<iostream>
#define MAX 300001
using namespace std;
int parent[MAX];

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	parent[y] = x;
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < MAX; i++)
		parent[i] = i;
	for (int i = 0; i < n - 2; i++) {
		int a, b; cin >> a >> b;
		merge(a, b);
	}
	for (int i = 2; i <= n; i++) {
		if (!isUnion(1, i)) {
			cout << 1 << " " << i;
			return 0;
		}
	}
	return 0;
}
