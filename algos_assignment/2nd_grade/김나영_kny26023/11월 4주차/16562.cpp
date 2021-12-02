#include <iostream>
#include <algorithm>

#define MAX 10001
#define INF 2e9
#define endl "\n"
using namespace std;

int fcost[MAX];
int p[MAX];
int total[MAX];

int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}

void friend_union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b)
		return;
	p[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i <= n; i++)
		p[i] = i;

	for (int i = 0; i < n; i++)
		cin >> fcost[i];
	
	int v, w;
	for (int i = 0; i < m; i++) {
		cin >> v >> w;
		friend_union(v - 1, w - 1);
	}
	
	fill(total, total + n, INF);
	for (int i = 0; i < n; i++)
		total[find(i)] = min(total[find(i)], fcost[i]);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (total[i] >= INF)
			continue;
		sum += total[i];
	}

	if (sum <= k)
		cout << sum << endl;
	else
		cout << "Oh no" << endl;
}
