#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#include<memory.h>
#include<stack>
#include<cstdlib>
#include<climits>
using namespace std;
int main() {
	int n;
	int arr[501][501] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);//대각선 라인을 따라 더한값으로 갱신
		}
	}
	//arr[n] 라인에는 각 라인 별 최댓값을 구한 값이 저장되어 있음
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, arr[n][i]); //합이 최대가 되는 경로에 있는 수의 합 출력
	}
	cout << ans;
}
