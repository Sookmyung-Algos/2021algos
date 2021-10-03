#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, hlth[20], plsr[20];
int dp[21][101]; // i번째 사람과 인사하고 h 체력이 남았을때에 기쁨 저장할 배열

int go(int i,int h) { // i번째 사람부터, 체력이 h부터 인사할건지 체크
	if (dp[i][h] > 0) return dp[i][h]; // 이미 저장한 적 있으면 꺼내어 씀
	if (i == n) return 0;

	int n1 = 0;
	if (h - hlth[i] > 0) // 인사를 하는 경우
		n1=plsr[i] + go(i + 1, h - hlth[i]); 
	int n2 = go(i + 1, h); // 인사를 하지 않는 경우
	return dp[i][h]=max(n1, n2); // n1과 n2 중 큰 값을 저장

}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", hlth + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", plsr + i);
	}

	cout<<go(0, 100); // 0번째 사람부터 체력이 100부터 시작
	return 0;
}
