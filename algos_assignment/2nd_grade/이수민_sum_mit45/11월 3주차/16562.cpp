// G3_16562 친구비

#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int N, M, k; // 학생 수 관계 수 돈
int arr[MAX];
int parent[MAX];

int Find(int u) {
	if (parent[u] == -1) return u; // parent 이면 부모 idx 반환
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	u = Find(u); v = Find(v);
	if (u == v) return; // 이미 같은 조직이라면

	// 다른 조직일때 합치기
	if (arr[u] < arr[v]) parent[v] = u; // 싼 친구 -> 부모가 되게
	else parent[u] = v;

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++) { // 일단 -1로 초기화
		parent[i] = -1;
	}
	for (int i = 1; i <= N; i++) { // 친구 비
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		Union(a, b);
	}

	// 그룹 내 가장 싼 친구를 사귀면 됨
	int money = 0; 

	for (int i = 1; i <= N; i++) {
		if (parent[i] == -1) {
			money += arr[i];
		}
	}

	// k보다 크면 ohno출력
	if (money > k) cout << "Oh no";
	else cout << money;

	return 0;
}
