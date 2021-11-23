// G1717_집합의 표현

// 합집합 0ab 
// 두 원소가 같은 집합에 포함되어 있는지 확인 1ab
#include <iostream>
#include <algorithm>
#define MAX 1000005
using namespace std;

int n, m;
int parent[MAX]; 
int height[MAX];

int Find(int u) {
	if (parent[u] == u) return u; // -1로 하면 부모들이 겹칠때 문제 발생
	return parent[u]= Find(parent[u]);
}

void Union(int u, int v) {
	u = Find(u); v = Find(v);
	if (u == v) return; // 같은 조직
	if (u < v) parent[v] = u;
	else parent[u] = v;
	
	/*if (height[u] < height[v]) swap(u, v);
	parent[v] = u;

	if (height[u] == height[v]) height[u]++;
	return true;*/
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i <= n; i++) { // -1로 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int check, a, b;
		cin >> check >> a >> b; // 0 1 3

		if (check == 0) { // union 합치기
			Union(a, b);
		}
		else if (check == 1) {
			int aset = Find(a); int bset = Find(b);
			if (aset == bset) { // 같은 집합이라면
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}

	}

	return 0;
}
