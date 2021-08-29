#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int set[100'001];

int find(int x){
	if(set[x] < 0) return x;
	return set[x] = find(set[x]);
}

void merge(int x, int y){
	if((x = find(x)) == (y = find(y))) return;
	if(set[x] < set[y]){	// x 집합 크기가 더 큼. 음수니까
		set[x] += set[y];
		set[y] = x;
	}
	else{
		set[y] += set[x];
		set[x] = y;
	}
}

struct st {
	int order, a, b, c;
} query[100001];

bool cmp(st x, st y) {
	return x.a > y.a;
}

int main() {
	int n, m, k, parent[100'001], student[100'001];
	int check[100'001] = {0};
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", parent + i);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", student + i); // 각 라운드 별
		check[student[i]]++;
	}
	for (int i = 0; i < k; ++i){
		scanf("%d%d%d", &query[i].a, &query[i].b, &query[i].c);
		query[i].order = i;
	}
	sort(query, query + k, cmp); // 라운드 높은 순으로 정렬.
	int cur = 0; // 가장 높은 라운드부터 차례로 봄.
	bool ans[100'001];
	for (int i = 0; i <= n; ++i) set[i] = -1;
	for (int i = 1; i <= n; ++i)
		if (parent[i] > 0 && !check[i]) merge(i, parent[i]);
	for (int i = m; i >= 0; --i) { // 각 라운드를 반대로 본다
		if (query[cur].a == i) { // 현재 라운드 쿼리이면
			do {
				ans[query[cur].order] = (find(query[cur].b) == find(query[cur].c));
				++cur;
			} while (cur < k && query[cur].a == i);
			if (cur == k) break;
		}
		if (i == 0) break;
		if (check[student[i]] > 1) { --check[student[i]]; continue; }
		if (parent[student[i]] > 0) merge(student[i], parent[student[i]]);
	}
	for (int i = 0; i < k; ++i)
		if (ans[i]) printf("Same Same;\n");
		else printf("No;\n");
	return 0;
}
