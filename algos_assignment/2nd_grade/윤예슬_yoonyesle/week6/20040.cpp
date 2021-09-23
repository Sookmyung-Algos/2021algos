#include <iostream>
using namespace std;

int set[500001];

int find(int x) {
	if (set[x] < 0) return x;
	return set[x] = find(set[x]);
}

void merge(int x, int y) {
	if ((x = find(x)) == (y = find(y))) return;
	if (set[x] < set[y]) {	// x 집합 크기가 더 큼. 음수니까
		set[x] += set[y];
		set[y] = x;
	}
	else {
		set[y] += set[x];
		set[x] = y;
	}
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) set[i] = -1;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		if (find(a) == find(b)) {
			printf("%d", i); return 0;
		}
		merge(a, b);
	}
	printf("0");
	return 0;
}
