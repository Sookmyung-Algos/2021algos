#include <iostream>
using namespace std;

int set[1000001];

int find(int i){
	if(set[i] < 0) return i;
	return set[i] = find(set[i]);
}

void merge(int i, int j){
	if((i = find(i)) == (j = find(j))) return;
	if(set[i] < set[j]) set[j] = i;
	else{
		set[j] = set[j] < set[i] - 1 ? set[j] : set[i] - 1;
		set[i] = j;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; ++i) set[i] = -1;
	while(m--){
		int x, a, b;
		scanf("%d%d%d", &x, &a, &b);
		if(x){
			if(find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else merge(a, b);
	}
	return 0;
}
