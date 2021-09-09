#include <iostream>

using namespace std;

int output[10];
int visited[10];
int N, M;
void dfs(int x) {
	if (x == M) {
		for (int i = 0; i < M; i++) {
			cout << output[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0)
		{
    		visited[i] = 1;
    		output[x] = i;
    		dfs(x + 1);
    		visited[i] = 0;
		}
	}
}
int main() {
	cin >> N >> M;
	dfs(0);
}
