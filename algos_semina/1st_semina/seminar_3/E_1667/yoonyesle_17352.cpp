#include <iostream>
using namespace std;

int set[300001];

int find(int x){
	if(set[x] < 0) return x;
	return set[x] = find(set[x]);
}

void merge(int x, int y){
	if((x = find(x)) == (y = find(y))) return;
	if(x < y){
		set[x] += set[y];
		set[y] = x;
	}
	else{
		set[y] += set[x];
		set[x] = y;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) set[i] = -1;
	for(int i = 0; i < n - 2; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		merge(a, b);
	}
	for (int i = 1; i <= n; ++i) {
		if (find(1) != find(i)) {
			printf("1 %d", i);
			return 0;
		}
	}
	return 0;
}
