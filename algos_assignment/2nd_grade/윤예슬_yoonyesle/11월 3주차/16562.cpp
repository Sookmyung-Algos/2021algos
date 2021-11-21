#include <iostream>
using namespace std;

int set[10001];

int find(int x){
	if(set[x] < 0) return x;
	return set[x] = find(set[x]);
}

void merge(int x, int y){
	if((x = find(x)) == (y = find(y))) return;
	if(set[x] < set[y]){
		set[x] += set[y];
		set[y] = x;
	}
	else{
		set[y] += set[x];
		set[x] = y;
	}
}

int main() {
	int n, m, k, a[10001], ans[10001] = {0};
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) set[i] = -1;
	while (m--) {
		int v, w;
		scanf("%d%d", &v, &w);
		merge(v, w);
	}
	for (int i = 1; i <= n; ++i) {
		int set_num = find(i);
		if (ans[set_num])
			ans[set_num] = min(ans[set_num], a[i]);
		else
			ans[set_num] = a[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += ans[i];
	if (sum > k)
		printf("Oh no");
	else
		printf("%d", sum);
	return 0;
}
