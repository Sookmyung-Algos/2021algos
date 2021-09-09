#include <iostream>
#include <cstring>
using namespace std;

int n, k, exer[9], ans = 0;
bool visited[9];

void dfs(int cnt, int weight ) {
	if (cnt == n) { //종결조건
		if (weight>= 500) {
			//cout << "500넘게 침" << endl;
			ans++;
			return;
		}
	}
	if (weight < 500) {
		//cout << "500보다 못 침" << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			//cout <<i+1<< "번째 기구 실행 후 : " << weight + exer[i] - 4 << endl;
			dfs(cnt + 1, weight+exer[i]-k);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> exer[i];
	}
	for (int i = 0; i < 9; i++) visited[i] = false;
	for (int i = 0; i < n; i++) {
		memset(visited, false, n+1);
		visited[i] = true;
		//cout << i + 1 << "번째 기구 실행 후 : " << 500 + exer[i] - 4 << endl;
		dfs(1, 500+exer[i]-k);
	}
	cout << ans;
}
