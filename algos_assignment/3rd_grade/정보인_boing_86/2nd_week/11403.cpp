#include <iostream>
#include <algorithm>

#define INF 10000000

using namespace std;

int n;
int graph[101][101];

void FW() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] + graph[k][j] > 1)
					graph[i][j] = 1;
			}
		}
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//if (i == j) {
				//graph[i][j] = 0;
			//}
			//else {
			graph[i][j] = INF;
			//}
		}
	}
}

int main() {
	int m;
	cin >> n;
	init();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> m;
			graph[i][j] = m;
		}
			

	}

	FW();

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			cout << graph[a][b] << " ";
		}
		cout << "\n";
	}
}
