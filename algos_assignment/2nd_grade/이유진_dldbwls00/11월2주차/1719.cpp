//코드 다시 복습할 것
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9
#define MAX (201)

int n, m;
int graph[MAX][MAX];
int answer[MAX][MAX];

int main() { 
	cin >> n >> m; 

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0; 
			else graph[i][j] = INF; 
		} 
	} 
	for (int i = 0; i < m; i++) {
		int from, to, dis; 
		cin >> from >> to>>dis; 
		graph[from][to] = dis; 
		graph[to][from] = dis; 
		answer[from][to] = to; 
		answer[to][from] = from; 
	} 
	for (int k = 1; k <= n; k++) { 
		for (int i = 1; i <= n; i++) { 
			for (int j = 1; j <= n; j++) { 
				if (graph[i][j] > graph[i][k] + graph[k][j]) { 
					graph[i][j] = graph[i][k] + graph[k][j]; 
					answer[i][j] = answer[i][k]; 
				}
			} 
		}
	} 
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= n;j++) { 
			if (answer[i][j] == 0) cout << "- "; 
			else cout << answer[i][j]<< ' ' ; 
		} 
		cout << "\n"; 
	} 
	return 0; 
}
