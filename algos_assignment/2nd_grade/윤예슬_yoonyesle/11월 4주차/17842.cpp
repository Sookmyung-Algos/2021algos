#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int edge[200001] = {0};
	for (int i = 0; i < n - 1; ++i) {
		int s, e;
		scanf("%d%d", &s, &e);
		edge[s]++; edge[e]++;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (edge[i] == 1) ++cnt;
	printf("%d", (cnt + 1) / 2);
	return 0;
}
