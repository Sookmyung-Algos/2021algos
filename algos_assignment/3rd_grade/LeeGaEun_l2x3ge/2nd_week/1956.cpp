#include <iostream>
#define min(a,b) (((a)<(b)) ? (a) : (b))
#define INF 987654321
using namespace std;

int v, e;
int city[401][401];


int main() {
	cin >> v >> e;
	//초기화
	for (int i = 1;i <= v;i++) {
		for (int j = 1;j <= v;j++) {
			city[i][j] = INF;
		}
	}
	//입력
	for (int i = 0;i < e;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a][b] = c;
	}
	//floydwarshall
	for (int k = 1;k <= v;k++) {
		for (int i = 1;i <= v;i++) {
			for (int j = 1;j <= v;j++) {
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}
	//구하기
	int min = INF;
	for (int i = 1;i <= v;i++) {
		if (min > city[i][i]) {
			min = city[i][i];
		}
	}
	if (min != INF)
		cout << min;
	else
		cout << -1;

	return 0;
}
