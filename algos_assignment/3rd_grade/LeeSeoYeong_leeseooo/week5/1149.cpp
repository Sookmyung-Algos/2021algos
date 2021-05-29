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
	int cost[3];
	int house[1001][3];
	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		//자신의 색깔 제외, 이전 집 색깔 둘 중 더 적은 비용 선택해서 저장
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + cost[2];
	}
	//가장 작은 비용 출력
	cout << min(house[n][2], min(house[n][0], house[n][1]));
}
// d(n) = cost[n][0] + min(d[n-1][1],d[n-1][2]
