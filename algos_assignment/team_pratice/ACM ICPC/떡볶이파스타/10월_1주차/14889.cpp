#include <iostream>
#include <math.h>
using namespace std;

int arr[21][21];
bool visit[21]; //true: start, false: link
int ans = 1234567890;
int n;

void combination(int n, int halfn);

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)	cin >> arr[i][j];
	}
	combination(0, 1); 
	cout << ans;
	return 0;
}
void combination(int x, int next) { //dfs 이용
	if (x == n / 2) {
		int start = 0, link = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (visit[i] == true && visit[j] == true) start += arr[i][j];
				if (visit[i] == false && visit[j] == false) link += arr[i][j];
			}
		}
		int temp = abs(start - link); //절댓값 구하기
		if (ans > temp) ans = temp; //갱신
		return;
	}

	for (int i = next; i < n; i++){ //중복 주의
		visit[i] = true;
		combination(x + 1, i + 1); //재귀
		visit[i] = false;
	}
}
