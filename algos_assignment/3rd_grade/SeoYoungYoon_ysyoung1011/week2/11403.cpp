//11403 경로 찾기
#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int n, graph[101][101];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num == 0) graph[i][j] = MAX;
			else graph[i][j] = 1;
		}
			
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == MAX) cout << '0' << ' ';
			else cout << '1' << ' ';
		}
		cout << '\n';
	}
}
