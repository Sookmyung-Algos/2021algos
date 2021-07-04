#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 251;
const int INF = 1e9 + 7;
int N, M, Q, d[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	memset(d, INF, sizeof(d));
    
	for (int i = 1; i <= N; i++) {
		d[i][i] = 0;
	}
    
	for (int i = 0; i < M; i++) {
		int ch, a, b;
		cin >> a >> b >> ch;
        
		d[a][b] = 0;
		d[b][a] = 1;
        
		if (ch)
			d[b][a] = 0;
	}
    
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	cin >> Q;
	while (Q--) {
		int s, e;
        
		cin >> s >> e;
		cout << d[s][e] << "\n";
	}
}
