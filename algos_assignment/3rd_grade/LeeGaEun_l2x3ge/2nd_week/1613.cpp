#include<iostream>
using namespace std;

int n, k, s;
int v[401][401] = { 0, };
void floydwarshall();

int main() {
  //입출력 시간 단축
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  //입력
	cin >> n >> k;
	for (int i = 0;i < k;i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = -1;
		v[b][a] = 1;
	}
	floydwarshall();
  //출력
	cin >> s;
	for (int i = 0;i < s;i++) {
		int a, b;
		cin >> a >> b;
		cout << v[a][b] << "\n";
	}
}

void floydwarshall() {
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (v[i][k] == 1 && v[k][j] == 1) {//뒤가 선행사건
					v[i][j] = 1;
				}
				else if(v[i][k] == -1 && v[k][j] == -1) {//앞이 
					v[i][j] = -1;
				}
			}
		}
	}
}
