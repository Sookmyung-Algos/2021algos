#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int a, b, c;
} node;

int set[1001];

int find(int i) {
	if (set[i] < 0) return i;
	return set[i] = find(set[i]);
}

void merge(int i, int j) {
	if ((i = find(i)) == (j = find(j))) return;
	if (set[i] < set[j]) {
		set[j] = i;
	}
	else {
		set[j] = set[j] < set[i] - 1 ? set[j] : set[i] - 1;
		set[i] = j;
	}
}

bool cmp(node a, node b) {
	return a.c < b.c;
}

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	node* in = new node[m];
	for (int i = 0; i < m; ++i) {
		cin >> in[i].a >> in[i].b >> in[i].c;
	}
	sort(in, in + m, cmp);
	for (int i = 0; i < n; ++i) set[i] = -1;
	for (int i = 0; i < m; ++i) {
		if (find(in[i].a) != find(in[i].b)) {
			merge(in[i].a, in[i].b);
			ans += in[i].c;
		}
	}
	cout << ans;
}
