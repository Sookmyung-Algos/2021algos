#include <iostream>
#include <algorithm>
using namespace std;

int n, w[100], v[100], k;
int dp[101][100001]; // i번째 물품에 weight 무게의 가치 저장
int go(int i, int weight) { // i번째 물품부터 무게가 weight부터 
	                        // 배낭에 넣을 것인지 체크하는 함수
	if (dp[i][weight] > 0) return dp[i][weight]; // 한번 저장했다면 dp배열에서 꺼내어 사용
	if (i == n) return 0;

	int n1 = 0;
	if (weight + w[i] <= k) // 물품을 배낭에 포함하는 경우
		n1=v[i] + go(i + 1, weight + w[i]); 
	int n2 = go(i + 1, weight); // 물품을 배낭에 포함하지 않는 경우
	return dp[i][weight]=max(n1, n2); // n1과 n2중 큰 값을 리턴
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", w + i, v + i);
	}

	cout << go(0, 0); // 0번째 물품부터 배낭에 무게가 0일때부터 시작
	return 0;
}
