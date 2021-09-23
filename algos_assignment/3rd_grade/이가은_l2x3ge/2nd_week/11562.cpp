#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#define INF 55555;
using namespace std;

int v[251][251] = { 0, };
int n, m;
void floydwarshall();

//INF: 못가는길 양방향: 갈 수 있음(이미 만들어짐(0))
//단방향(순): 갈수있음(이미 만들어짐(0)) 단방향(역): @변경@ (1)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	//초기화
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			v[i][j] = INF;
			if (i == j) {
				v[i][j] = 0;
			}
		}
	}
	//입력
	for (int i = 0;i < m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b] = 0;
		v[b][a] = 0;
		if (c == 0) {
			v[b][a] = 1;
		}
	}
	floydwarshall();
	//출력
	int tmp, a, b;
	cin >> tmp;
	for (int i = 0;i < tmp;i++) {
		cin >> a >> b;
		cout << v[a][b] << "\n";
	}
}

void floydwarshall() {
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
}
